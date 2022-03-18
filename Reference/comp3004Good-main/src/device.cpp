#include <QDebug>
#include "device.h"

Device::Device(QObject *parent) : QObject(parent)
{
    this->powerLevel = 100;
    this->isOn = false;
    this->isInContact = true;
    this->currentTreatment = new Treatment();
    treatmentStarted = false;
    recording = false;
}

Device::~Device()
{
    delete currentTreatment;
    for (int i = 0; i < recordedTreatments.size(); i++)
        delete recordedTreatments[i];
}

/*
 *
 *
 * The following will be our getters
 *
 *
 */

float Device::getCurrentFrequency()
{
   return currentTreatment->getFrequency();
}

Waveform Device::getCurrentWaveform()
{
   return currentTreatment->getWaveform()	;
}

int Device::getPowerLevel()
{
    return powerLevel;
}

bool Device::getIsOn()
{
    return isOn;
}

bool Device::getIsInContact()
{
    return isInContact;
}

int Device::getCurrentTimeCycle()
{
    return currentTreatment->getTime();
}

int Device::getTreatmentCurrent()
{
    return currentTreatment->getCurrent();
}

int Device::getNumberOfRecordedTreatment()
{
    return recordedTreatments.length();
}

bool Device::isRecording()
{
    return recording;
}

bool Device::getTreatmentStarted(){
    return treatmentStarted;
}


/*
 *
 *
 * End of our getters
 *
 *
 */

/*
 *
 *
 * The following will be our setters
 *
 *
 */

void Device::setPowerLevel(int level)
{
    this->powerLevel = level;
}

void Device::setIsOn(bool on)
{
    this->isOn = on;
}

void Device::setIsInContact(bool contact)
{
    this->isInContact = contact;
}

void Device::setCurrent(int current)
{
    currentTreatment->setCurrent(current);
}

void Device::changeCurrentFrequency(float frequency)
{
    currentTreatment->setFrequency(frequency);
}

void Device::changeCurrentWaveform(Waveform waveform)
{
    currentTreatment->setWaveform(waveform);
}

void Device::setTimeCycle(int time)
{
    currentTreatment->setTime(time);
}

void Device::toggleRecording()
{
   recording = !recording;
}

void Device::startTreatment(bool start)
{
    treatmentStarted = start;
}
/*
 *
 *
 * End of our setters
 *
 *
 */

//function to replay the recorded treatment. Takes the indexof the treatement needed.
void Device::replayRecordedTreatment(int index)
{
    delete currentTreatment;
    currentTreatment = new Treatment(recordedTreatments.at(index));
}

//Adds the recorded traetment to a Vector
void Device::recordCurrentTreatment()
{
    recordedTreatments.push_back(new Treatment(currentTreatment));
}

void Device::drainBattery()
{
    if (powerLevel > 0)
        drainBatteryBy(treatmentStarted ? currentTreatment->getCurrent()/100 + 1 : 1);
}

//change the increment of our battery draining.
void Device::drainBatteryBy(int decrement)
{
    powerLevel -= decrement;
}
