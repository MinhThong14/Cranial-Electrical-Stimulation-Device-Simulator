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
}

void Device::updateTreatment()
{
    if(turnedOn && treatmentInProgress){
        isIdle = false;
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
}

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

void Device::updateTimeout(){
    if(turnedOn && isIdle && !treatmentInProgress){
        powerDown();
        popupAlert("Treatment not started for 30 seconds. Device will shut down.");
    }
    isIdle = true;
}

void Device::setBatteryInterval(int interval){
    batteryTimer->setInterval(interval);
}

void Device::setBatteryAmount(int amount){
    drainBatteryBy = amount;
}

void Device::powerButtonPressed(){
    if (turnedOn){
        powerDown();
    }
    else{
        powerUp();
    }
}

void Device::powerUp(){
    turnedOn = true;
    batteryTimer->start();
    timeoutTimer->start();
}

void Device::powerDown(){
    turnedOn = false;
    treatmentInProgress = false;

    batteryTimer->stop();
    timeoutTimer->stop();
    treatmentTimer->stop();

    setTreatmentTime(20);
    setSessionType(new AlphaSession());
    setIntensity(5);
    treatmentTimeRemaining = 0;
}

void Device::chargeBattery(int amount){
    battery->charge(amount);
}

void Device::drainBattery(int amount){
    battery->drain(amount);
}

void Device::setBatteryCharge(int value){
    battery->setPower(value);
}

void Device::fullCharge(){
    battery->fullCharge();
}

void Device::powerSurge(){
    powerDown();
}

void Device::setTreatmentTime(int time){
    if(!treatmentInProgress){
        curTreatment->setLength(time);
        isIdle = false;
    }
}

void Device::setSessionType(Session* sessionType){
    if(!treatmentInProgress){
        curTreatment->setSessionType(sessionType);
        isIdle = false;
    }
}

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

void Device::increaseIntensity(){
    if(turnedOn && treatmentInProgress){
        int intensity = curTreatment->getIntensity();
        if(intensity < 8){
            curTreatment->setIntensity(intensity + 1);
        }
    }
}

void Device::decreaseIntensity(){
    if(turnedOn && treatmentInProgress){
        int intensity = curTreatment->getIntensity();
        if(intensity > 1){
            curTreatment->setIntensity(intensity - 1);
        }
    }
}

int Device::getBatteryPower(){
    return battery->getPower();
}

int Device::getTreatmentTime(){
    return curTreatment->getLength();
}

int Device::getIntensity(){
    return curTreatment->getIntensity();
}

Session* Device::getSessionType(){
    return curTreatment->getSessionType();
}

TreatmentData* Device::getRecording(int index){
    return recordedTreatments.at(index);
}

int Device::getTreatmentTimeRemaining(){
    return treatmentTimeRemaining;
}

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

void Device::replayRecording(int index){
    delete curTreatment;
    TreatmentData* recTreatment = recordedTreatments.at(index);
    curTreatment = new TreatmentData(
                recTreatment->getLength(),
                recTreatment->getSessionType(),
                recTreatment->getIntensity()
    );
}

void Device::recordTreatment(){
    recordedTreatments.append(curTreatment);
}

