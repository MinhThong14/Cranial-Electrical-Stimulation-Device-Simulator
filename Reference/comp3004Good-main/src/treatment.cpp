#include <QDebug>
#include "treatment.h"

Treatment::Treatment(float frequency, Waveform waveForm, int time, int current, bool isAdministering, QObject *parent) : QObject(parent)
{
    this->frequency = frequency;
    this->waveForm = waveForm;
    this->time = time;
    this->remainingTime = time;
    this->current = current;
    this->isAdministering = isAdministering;
}

Treatment::Treatment(Treatment * other)
{
    frequency = other->getFrequency();
    waveForm = other->getWaveform();
    time = other->getTime();
    current = other->getCurrent();
}

Treatment::~Treatment()
{

}

/*
 *
 *
 * The following will be our getters
 *
 *
 */

float Treatment::getFrequency()
{
    return frequency;
}

Waveform Treatment::getWaveform()
{
    return waveForm;
}

int Treatment::getTime()
{
    return time;
}

int Treatment::getRemainingTime()
{
    return remainingTime;
}

int Treatment::getCurrent()
{
    return current;
}

bool Treatment::getIsAdministering()
{
    return isAdministering;
}

/*
 *
 *
 * End of our setters
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

void Treatment::setFrequency(float frequency)
{
    this->frequency = frequency;
}

void Treatment::setWaveform(Waveform waveform)
{
    this->waveForm = waveform;
}

void Treatment::setRemainingTime(int time)
{
    this->remainingTime = time;
}

void Treatment::setCurrent(int current)
{
    this->current = current;
}

void Treatment::setIsAdministering(bool administer)
{
    this->isAdministering = administer;
}

void Treatment::setTime(int time)
{
    this->time = time;
}

/*
 *
 *
 * TEnd of our setters
 *
 *
 */
