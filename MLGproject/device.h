#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QList>
#include <QTimer>
#include <QString>
#include <QMessageBox>

#include <log.h>
#include <battery.h>
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
    void fullCharge();

    void setTreatmentTime(int time);
    void setSessionType(Session* sessionType);
    void setIntensity(int i);
    void setBatteryInterval(int interval);
    void setBatteryAmount(int amount);
    void setIsRecording(bool b);
    void setTouchingSkin(bool b);
    void increaseIntensity();
    void decreaseIntensity();

    int getTreatmentTime();
    int getIntensity();
    int getBatteryPower();
    Session* getSessionType();
    TreatmentData* getRecording(int index);
    int getTreatmentTimeRemaining();
    bool isPowerOn();
    QList<TreatmentData*>* getRecordedTreatments();

    void startTreatment();
    void replayRecording(int index);
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
    bool treatmentPaused;
    int treatmentTimeRemaining;
    int drainBatteryBy;

    void displayLowBattery();
    void powerUp();
    void powerDown();
    TreatmentData* copyTreatment(TreatmentData* treatment);
};

#endif // DEVICE_H
