#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <log.h>
#include <treatmentdata.h>

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
    void increaseFrequency();
    void decreaseFrequency();
    void changeWaveType();
    void pressStartButton();
    void isReadyToStart(bool isReady);
    void toggleSkinTouch(QString value);
    void reduceTime();
    void drainBattery();
    void manuallyDrainTheBattery();
    void displayBattery();
    void displayHistory();
    void addToHistoryPressed();

private:
    Ui::MainWindow *ui;
    bool isHistoryClicked;
    bool isTimeZero;
    int skin5sTimer = 0;
    int timmer30s = 0;
    void check30Seconds();
    void showAlert(QString message= "");
    void resetAllVariables();

};
#endif // MAINWINDOW_H
