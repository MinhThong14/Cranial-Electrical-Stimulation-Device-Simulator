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
    void update();

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

    void startTreatment();
    void replayRecordedTreatment(int index);
    void recordTreatment();

private:
    Battery* battery;
    QTimer* UpdateTimer;
    QTimer* timeoutTimer;
    QList<TreatmentData*> recordedTreatments;
    TreatmentData* curTreatment;
    bool turnedOn;
    bool treatmentInProgress;
    bool isIdle;

    /*void disableAllButtons();
    void disableButton(QString);
    void enableAllButtons();
    void enableButton(QString);*/

    void alert(QString);
    void displayLowBattery();
    void powerUp();
    void powerDown();
    void checkTimeout();
    void init();
};

#endif // DEVICE_H
