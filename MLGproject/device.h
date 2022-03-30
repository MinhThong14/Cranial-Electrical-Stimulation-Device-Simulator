#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QString>
#include <QMessageBox>

#include <log.h>
#include <battery.h>
#include <session.h>
#include <sessiontypes.h>
#include <treatmentdata.h>

#include <string.h>


class Device : public QObject
{
    Q_OBJECT

public:
    Device(QObject *parent = NULL);
    ~Device();
    void updateTreatment();
    void updateBattery();
    void updateTimeout();

    void powerButtonPressed();
    void chargeBattery(int amount);
    void drainBattery(int amount);
    void setBatteryCharge(int value);
    void powerSurge();

    void replayRecording(int index);
    void setTreatmentTime(int time);
    void setIntensity(int intensity);
    void setFrequency(float freq);
    void setSessionType(Session* sessionType);
    void setBatteryInterval(int interval);
    void setBatteryAmount(int amount);
    void setIsRecording(bool b);
    void setTouchingSkin(bool b);

    int getTreatmentTime();
    int getIntensity();
    int getBatteryPower();
    Session* getSessionType();
    TreatmentData* getRecording(int index);
    int getTreatmentTimeRemaining();

    void startTreatment();
    void replayRecordedTreatment(int index);
    void recordTreatment();

private:
    Battery* battery;
    QTimer* treatmentTimer;
    QTimer* timeoutTimer;
    QTimer* batteryTimer;
    QList<TreatmentData*> recordedTreatments;
    TreatmentData* curTreatment;
    bool turnedOn;
    bool treatmentInProgress;
    bool isIdle;
    bool isRecording;
    bool isTouchingSkin;
    int batteryDrainAmount;
    int treatmentTimeRemaining;

    void alert(QString);
    void displayLowBattery();
    void powerUp();
    void powerDown();
};

#endif // DEVICE_H
