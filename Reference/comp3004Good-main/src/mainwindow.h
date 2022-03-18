#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QMessageBox>

#include "device.h"

/***
 * Purpose: The Control object of the simulator
 *
 * */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pressPowerButton();
    void changeFrequency();
    void changeWaveform();
    void enableDevice(bool enable);
    void chargeDeviceToFull();
    void decreaseBattery();
    void manuallyDecreaseBattery();
    void displayBatteryText();
    void decreaseTime();
    void toggleSkinInContact(QString value);
    void exceedDeviceCurrent();
    void currentExceeded();
    void timeButtonPressed();
    void upButtonPressed();
    void downButtonPressed();
    void intensityPressed();
    void historyPressed();
    void recordButtonPressed();
    void fastForwardPressed();

private:
    Ui::MainWindow *ui;
    Device* device;
    bool timeButtonClicked;
    bool intensityButtonClicked;
    bool historyButtonClicked;
    bool timerReachedZero;
    int skin5sTimerIndicator = 0;
    int timer30sIndicator = 0;

    QTimer* lcdTimer = new QTimer(this);
    QTimer* batteryTimer = new QTimer(this);
    QTimer* currentLevelTimer = new QTimer(this);
    QTimer* skinTimer = new QTimer(this);
    QTimer* inUse30sTimer = new QTimer(this);

    void disableAllButtonsExcept(QString);
    void enableAllButtons();
    void updateTimerSelect();
    void recordTreatment();
    void startTimerProtocol();
    void showAlert(QString message = "");
    void resetWindowVariables();
    void refreshAllButtonBasedOnCurrentTreatment();
    void padsFellProtocol();
    void check30Sec();
    void startButtonClicked();
    void fixCurrent();
    void importantButtonsEnabled();
};
#endif // MAINWINDOW_H
