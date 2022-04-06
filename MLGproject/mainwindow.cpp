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
    connect(ui->historyButton, SIGNAL(released()), this, SLOT (historyButton()));
    connect(ui->drainBattery1, SIGNAL(released()), this, SLOT (drainBatteryBy3()));
    connect(ui->drainBattery2, SIGNAL(released()), this, SLOT (drainBatteryBy10()));
    connect(ui->chargeDeviceButton, SIGNAL(released()), this, SLOT (chargeBatteryToFull()));
    connect(ui->upButton, SIGNAL(released()), this, SLOT (increaseIntensity()));
    connect(ui->downButton, SIGNAL(released()), this, SLOT (decreaseIntensity()));
    connect(ui->checkBox,SIGNAL(clicked(bool)),this,SLOT(toggleCheckbox(bool)));
    connect(ui->contackSkinDropbox,SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(toggleAttachment(const QString&)));

    connect(ui->time20Button, SIGNAL(clicked()), this, SLOT (select20MinSession()));
    connect(ui->time45Button, SIGNAL(clicked()), this, SLOT (select45MinSession()));
    connect(ui->customTimeButton, SIGNAL(clicked()), this, SLOT (selectCustomSession()));
    connect(ui->alphaButton, SIGNAL(clicked()), this, SLOT (selectAlphaSession()));
    connect(ui->betaButton, SIGNAL(clicked()), this, SLOT (selectBetaSession()));
    connect(ui->deltaButton, SIGNAL(clicked()), this, SLOT (selectDeltaSession()));
    connect(ui->thetaButton, SIGNAL(clicked()), this, SLOT (selectThetaSession()));

    ui->batteryBar->setTextVisible(false);
    ui->customTimeBox->setValidator(new QIntValidator(0, 100, this));

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

    if(device->isPowerOn()){
        ui->onLight->setStyleSheet("#onLight{border-image: url(:/pngs/onLightGreen.png);}");

    }else{
        ui->onLight->setStyleSheet("#onLight{border-image: url(:/pngs/onLight.png);}");
        ui->treatmentList->clear();
        ui->customTimeBox->clear();
    }
}

void MainWindow::powerButton() {
    device->powerButtonPressed();
    setup();
}

void MainWindow::setup() {
    if(device->isPowerOn()){
        QList<TreatmentData*>* treatments = device->getRecordedTreatments();
        for(int i = treatments->length() - 1; i >= 0; i--){
            TreatmentData* treatment = treatments->at(i);
            string treatmentLabel = "T" + to_string(treatments->length() - i) + ": "
                    + to_string(treatment->getLength()) + " min, "
                    + treatment->getSessionType()->getName() + ", "
                    + "Int " + to_string(treatment->getIntensity());
            ui->treatmentList->addItem(QString::fromStdString(treatmentLabel));
        }
    }
}

void MainWindow::startButton() {
    setSessionTime();
    device->startTreatment();
}

void MainWindow::historyButton() {
    int index = (ui->treatmentList->currentIndex()).row();
    selectedTime = timeCustom;
    device->replayRecording(index);
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
}

void MainWindow::decreaseIntensity(){
    device->decreaseIntensity();
}

void MainWindow::toggleCheckbox(bool checked){
    device->setIsRecording(checked);
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
    selectedTime = time20;
    log("Selected 20 minute session");
}

void MainWindow::select45MinSession(){
    selectedTime = time45;
    log("Selected 45 minute session");
}

void MainWindow::selectCustomSession(){
    selectedTime = timeCustom;
    log("Selected custom time session");
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

void MainWindow::setSessionTime() {
    int time = 0;
    switch(selectedTime) {
        case time20:
            time = 20;
            break;
        case time45:
            time = 45;
            break;
        case timeCustom:
            QString timeString = ui->customTimeBox->text();
            time = timeString.toInt();
            break;
    }
    device->setTreatmentTime(time);
}
