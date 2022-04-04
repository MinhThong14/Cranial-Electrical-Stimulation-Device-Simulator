#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    device = new Device();

    updateTimer = new QTimer();
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::update);
    updateTimer->start(1);

    connect(ui->onButton, SIGNAL(released()), this, SLOT (powerButton()));
    connect(ui->checkButton, SIGNAL(released()), this, SLOT (startButton()));
    connect(ui->drainBattery1, SIGNAL(released()), this, SLOT (drainBatteryBy3()));
    connect(ui->drainBattery2, SIGNAL(released()), this, SLOT (drainBatteryBy10()));
    connect(ui->chargeDeviceButton, SIGNAL(released()), this, SLOT (chargeBatteryToFull()));
    connect(ui->upButton, SIGNAL(released()), this, SLOT (increaseIntensity()));
    connect(ui->downButton, SIGNAL(released()), this, SLOT (decreaseIntensity()));
    connect(ui->contackSkinDropbox,SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(toggleAttachment(const QString&)));

    connect(ui->time20Button, SIGNAL(clicked()), this, SLOT (select20MinSession()));
    connect(ui->time45Button, SIGNAL(clicked()), this, SLOT (select45MinSession()));
    connect(ui->alphaButton, SIGNAL(clicked()), this, SLOT (selectAlphaSession()));
    connect(ui->betaButton, SIGNAL(clicked()), this, SLOT (selectBetaSession()));
    connect(ui->deltaButton, SIGNAL(clicked()), this, SLOT (selectDeltaSession()));
    connect(ui->thetaButton, SIGNAL(clicked()), this, SLOT (selectThetaSession()));

    ui->batteryBar->setTextVisible(false);

    log("Application Started");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete device;
}

void MainWindow::update(){
    ui->batteryBar->setValue(device->getBatteryPower());
    ui->intensityCounter->display(device->getIntensity());
    ui->lcdNumber->display(device->getTreatmentTimeRemaining());
}

void MainWindow::powerButton() {
    device->powerButtonPressed();
    log("Power Button pressed");
}

void MainWindow::startButton() {
    device->startTreatment();
    log("Start Button pressed");
}

void MainWindow::drainBatteryBy3() {
    device->drainBattery(3);
}

void MainWindow::drainBatteryBy10() {
    device->drainBattery(10);
}

void MainWindow::chargeBatteryToFull() {
    device->fullCharge();
}

void MainWindow::increaseIntensity(){
    device->increaseIntensity();
    log("Intensity is now " + to_string(device->getIntensity()));
}

void MainWindow::decreaseIntensity(){
    device->decreaseIntensity();
    log("Intensity is now " + to_string(device->getIntensity()));
}

void MainWindow::toggleAttachment(const QString& value){
    if(value.toStdString() == "True"){
        device->setTouchingSkin(true);
    }
    else{
        device->setTouchingSkin(false);
    }
}

void MainWindow::select20MinSession(){
    device->setTreatmentTime(20);
    log("Selected 20 minute session");
}

void MainWindow::select45MinSession(){
    device->setTreatmentTime(45);
    log("Selected 45 minute session");
}

void MainWindow::selectAlphaSession(){
    device->setSessionType(new AlphaSession);
    log("Selected Alpha session");
}

void MainWindow::selectBetaSession(){
    device->setSessionType(new BetaSession);
    log("Selected Beta session");
}

void MainWindow::selectDeltaSession(){
    device->setSessionType(new DeltaSession);
    log("Selected Delta session");
}

void MainWindow::selectThetaSession(){
    device->setSessionType(new ThetaSession);
    log("Selected Theta session");
}
