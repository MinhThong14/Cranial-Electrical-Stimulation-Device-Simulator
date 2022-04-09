#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{
    battery = new Battery();
    curTreatment = new TreatmentData(20, new AlphaSession(), 5);

    turnedOn = false;
    treatmentInProgress = false;
    isIdle = false;
    isRecording = false;
    isTouchingSkin = true;
    treatmentPaused = false;

    treatmentTimeRemaining = 0;
    drainBatteryBy = 1;

    treatmentTimer = new QTimer();
    timeoutTimer = new QTimer();
    batteryTimer = new QTimer();

    connect(treatmentTimer, &QTimer::timeout, this, &Device::updateTreatment);
    connect(timeoutTimer, &QTimer::timeout, this, &Device::updateTimeout);
    connect(batteryTimer, &QTimer::timeout, this, &Device::updateBattery);

    timeoutTimer->start(30000);
    batteryTimer->start(3000);
}

Device::~Device() {
    delete battery;
    delete curTreatment;
    delete treatmentTimer;
    delete timeoutTimer;
    delete batteryTimer;

    for(int i = 0; i < recordedTreatments.length(); i++){
        delete recordedTreatments.at(i);
    }
}

// Updates the treatment every second while turnedOn and treatmentInProgress
void Device::updateTreatment()
{
    if(turnedOn && treatmentInProgress && isTouchingSkin){
        isIdle = false;
        treatmentPaused = false;
        if (--treatmentTimeRemaining <= 0){
            treatmentTimeRemaining = 0;
            treatmentInProgress = false;
            if (isRecording){
                recordTreatment();
            }
            popupAlert("Treatment is over, turning off the device.");
            powerDown();
        }
    }
    else if (turnedOn && treatmentInProgress && !isTouchingSkin && !treatmentPaused){
        treatmentPaused = true;
        popupAlert("Device not in contact with skin, treatment paused.");
    }
}

// Updates the battery every 3 seconds while turnedOn
void Device::updateBattery(){
    if(turnedOn){
        if (battery->getPower() <= 0){
            popupAlert("Battery at 0%. Device will shut down.");
            powerDown();
        }
        else {
            if (battery->getPower() == 10){
                popupAlert("Warning, battery is low at 10%.");
            }
            battery->drain(drainBatteryBy);
        }
    }
}

// Updates the battery every 30 seconds while turnedOn, if device is idle then powerDown device
void Device::updateTimeout(){
    if(turnedOn && isIdle && !treatmentInProgress){
        powerDown();
        popupAlert("Treatment not started for 30 seconds. Device will shut down.");
    }
    isIdle = true;
}

// Sets the battery batteryTimer interval
void Device::setBatteryInterval(int interval){
    batteryTimer->setInterval(interval);
}

// Sets the amount the battery drains each batteryTimer interval
void Device::setBatteryAmount(int amount){
    drainBatteryBy = amount;
}

// If device is turnedOn, powerDown else powerUp
void Device::powerButtonPressed(){
    if (turnedOn){
        powerDown();
    }
    else{
        powerUp();
    }
}

// Turn on device and start update loop timers
void Device::powerUp(){
    turnedOn = true;
    batteryTimer->start();
    timeoutTimer->start();
}

// Turn off device and stop update loop timers
void Device::powerDown(){
    turnedOn = false;
    treatmentInProgress = false;

    batteryTimer->stop();
    timeoutTimer->stop();
    treatmentTimer->stop();

    treatmentTimeRemaining = 0;
}

// Increase battery power by amount
void Device::chargeBattery(int amount){
    battery->charge(amount);
}

// Decrease battery power by amount
void Device::drainBattery(int amount){
    battery->drain(amount);
}

// Set battery power by amount
void Device::setBatteryCharge(int value){
    battery->setPower(value);
}

// Fully charge battery
void Device::fullCharge(){
    battery->fullCharge();
}

// Sets length of curTreatment
void Device::setTreatmentTime(int time){
    if(!treatmentInProgress){
        curTreatment->setLength(time);
        isIdle = false;
    }
}

// Sets Session of curTreatment
void Device::setSessionType(Session* sessionType){
    if(!treatmentInProgress){
        curTreatment->setSessionType(sessionType);
        isIdle = false;
    }
}

// Sets intensity of curTreatment
void Device::setIntensity(int i){
    if(i > 0 && i < 9){
        curTreatment->setIntensity(i);
    }
}

void Device::setIsRecording(bool b){
    isRecording = b;
    isIdle = false;
}

void Device::setTouchingSkin(bool b){
    isTouchingSkin = b;
}

// Increments intensity of curTreatment by 1
void Device::increaseIntensity(){
    if(turnedOn){
        int intensity = curTreatment->getIntensity();
        if(intensity < 8){
            curTreatment->setIntensity(intensity + 1);
        }
    }
}

// Decrements intensity of curTreatment by 1
void Device::decreaseIntensity(){
    if(turnedOn){
        int intensity = curTreatment->getIntensity();
        if(intensity > 1){
            curTreatment->setIntensity(intensity - 1);
        }
    }
}

// Gets power of battery
int Device::getBatteryPower(){
    return battery->getPower();
}

// Gets length of curTreatment
int Device::getTreatmentTime(){
    return curTreatment->getLength();
}

// Gets SessionType of curTreatment
int Device::getIntensity(){
    return curTreatment->getIntensity();
}

// Gets SessionType of curTreatment
Session* Device::getSessionType(){
    return curTreatment->getSessionType();
}

TreatmentData* Device::getRecording(int index){
    return recordedTreatments.at(index);
}

int Device::getTreatmentTimeRemaining(){
    return treatmentTimeRemaining;
}

bool Device::isPowerOn(){
    return turnedOn;
}

QList<TreatmentData*>* Device::getRecordedTreatments(){
    return &recordedTreatments;
}

// Begin running a treatment
void Device::startTreatment(){
    if(turnedOn && !treatmentInProgress){
        if(isTouchingSkin){
            treatmentInProgress = true;
            isIdle = false;
            treatmentTimeRemaining = curTreatment->getLength();
            treatmentTimer->start(1000);
            popupAlert("Starting Session " + curTreatment->getSessionString());
        }
        else{
            popupAlert("Device not in contact with skin, treatment cannot start.");
        }
    }
}

// Set curTreatment to a copy of a recorded treatment
void Device::replayRecording(int index){
    if(index >= 0 && index < recordedTreatments.length()){
        delete curTreatment;
        TreatmentData* recTreatment = recordedTreatments.at(recordedTreatments.length() - index - 1);
        curTreatment = copyTreatment(recTreatment);
        startTreatment();
    }
}

// Adds a copy of treatment to recordedTreatments
void Device::recordTreatment(){
    TreatmentData* newTreatment = copyTreatment(curTreatment);
    recordedTreatments.append(newTreatment);
}

// Return a copy of given treatment
TreatmentData* Device::copyTreatment(TreatmentData* treatment){
    string sessionName = treatment->getSessionType()->getName();
    Session* session;

    if(sessionName == "Alpha") {
        session = new AlphaSession();
    }
    else if(sessionName == "Beta 1") {
        session = new BetaSession();
    }
    else if(sessionName == "Delta") {
        session = new DeltaSession();
    }
    else if(sessionName == "Theta") {
        session = new ThetaSession();
    }

    TreatmentData* newTreatment = new TreatmentData(
                treatment->getLength(),
                session,
                treatment->getIntensity());

    return newTreatment;
}

