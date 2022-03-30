#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{
    batteryDrainAmount = 1;

    connect(treatmentTimer, &QTimer::timeout, this, &Device::updateTreatment);
    connect(timeoutTimer, &QTimer::timeout, this, &Device::updateTimeout);
    connect(batteryTimer, &QTimer::timeout, this, &Device::updateBattery);

    timeoutTimer->start(30000);
    batteryTimer->start(3000);

    battery = new Battery();
    Session* session = new AlphaSession();
    curTreatment = new TreatmentData(20, session, 5);
    turnedOn = false;
    treatmentInProgress = false;
    isIdle = false;
    isRecording = false;
    isTouchingSkin = true;
    treatmentTimeRemaining = 0;
}

Device::~Device()
{

}

void Device::updateTreatment()
{
    isIdle = false;
    if (turnedOn && treatmentTimeRemaining-- <= 0){
        treatmentInProgress = false;
        treatmentTimer->stop();
        if (isRecording){
            recordTreatment();
        }
    }
}

void Device::updateBattery(){
    if (battery->getPower() <= 0){
        popupAlert("Battery at 0%. Device will shut down.");
        powerDown();
    }
    else if (turnedOn){
        if (battery->getPower() == 10){
            popupAlert("Warning, battery is low at 10%.");
        }
        battery->drain(batteryDrainAmount);
    }
}

void Device::updateTimeout(){
    if(isIdle && !treatmentInProgress){
        powerDown();
        popupAlert("Treatment not started for 30 seconds. Device will shut down.");
    }
    isIdle = true;
}

void Device::setBatteryInterval(int interval){
    batteryTimer->setInterval(interval);
}

void Device::setBatteryAmount(int amount){
    batteryDrainAmount = amount;
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
    timeoutTimer->start();
}

void Device::powerDown(){
    turnedOn = false;
    timeoutTimer->stop();
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

void Device::powerSurge(){
    powerDown();
}

void Device::setTreatmentTime(int time){
    curTreatment->setLength(time);
    isIdle = false;
}

void Device::setIntensity(int intensity){
    curTreatment->setIntensity(intensity);
    isIdle = false;
}

void Device::setSessionType(Session* sessionType){
    curTreatment->setSessionType(sessionType);
    isIdle = false;
}

void Device::setIsRecording(bool b){
    isRecording = b;
    isIdle = false;
}

void Device::setTouchingSkin(bool b){
    isTouchingSkin = b;
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
    if(isTouchingSkin){
        treatmentInProgress = true;
        isIdle = false;
        treatmentTimeRemaining = curTreatment->getLength();
        treatmentTimer->start(1000);
    }
    else{
        popupAlert("Device not in contact with skin, treatment cannot start.");
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

