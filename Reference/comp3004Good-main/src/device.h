#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QVector>
#include <QTimer>
#include "treatment.h"

/***
 * Purpose: Device class to hold information about a device and administer and modify treatments
 *
 * void changeCurrentFrequency(float): modifies a treatment's frequency
 * void changeCurrentWaveform(float): modifies a treatment's Waveform
 * void toggleRecording(): modifies whether a treatment is being recorded or not
 * void replayRecordedTreatment(int index): sets the device's currentTreatment member to a stored Treatment object at a specific index in recordedTreatments
 * void drainBattery(): Device's default behaviour for draining its powerLevel
 * void drainBatteryBy(int): decreases the device's powerLevel by a specific amount
 *
 * */


class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = nullptr);
    ~Device();

    void changeCurrentFrequency(float);
    void changeCurrentWaveform(Waveform);
    float getCurrentFrequency();
    Waveform getCurrentWaveform();

    int getPowerLevel();
    bool getIsOn();
    bool getIsInContact();
    int getCurrentTimeCycle();
    int getTreatmentCurrent();
    int getNumberOfRecordedTreatment();
    bool isRecording();

    void setPowerLevel(int level);
    void setIsOn(bool on);
    void setIsInContact(bool contact);
    void setCurrent(int current);
    void setTimeCycle(int time);
    void toggleRecording();
    void replayRecordedTreatment(int index);

    void startTreatment(bool start = true);
    void recordCurrentTreatment();

    void drainBattery();
    void drainBatteryBy(int);
    bool getTreatmentStarted();

signals:

private:
    int powerLevel;
    bool isOn;
    QVector<Treatment*> recordedTreatments;
    bool isInContact;
    QTimer timer;
    Treatment* currentTreatment;
    bool treatmentStarted;
    bool recording;

};

#endif // DEVICE_H
