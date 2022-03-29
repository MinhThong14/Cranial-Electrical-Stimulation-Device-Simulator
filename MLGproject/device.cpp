#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{

}

Device::~Device()
{

}

void Device::update()
{
    battery->update();
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

void Device::checkTimeout(){
    if(isIdle && !treatmentInProgress){
        //timeoutTimer->stop();
        powerDown();
        //alert("Treatment not started for 30 seconds. Device will shut down.");
    }
    isIdle = true;
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

void Device::setFrequency(float freq){
    isIdle = false;
}

void Device::setSessionType(Session* sessionType){
    curTreatment->setSessionType(sessionType);
    isIdle = false;
}

void Device::setIntensity(int intensity){
    curTreatment->setIntensity(intensity);
    isIdle = false;
}

void Device::startTreatment(){
    treatmentInProgress = true;
    isIdle = false;
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

