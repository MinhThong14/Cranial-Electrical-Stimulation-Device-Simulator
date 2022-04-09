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

//Updates the Main Window GUI every fraction of a second
void MainWindow::update(){
    ui->batteryBar->setValue(device->getBatteryPower());
    ui->intensityCounter->display(device->getIntensity());
    ui->lcdNumber->display(device->getTreatmentTimeRemaining());

    if(device->isPowerOn()){
        ui->onLight->setStyleSheet("#onLight{border-image: url(:/pngs/onLightGreen.png);}");

        if(selectedTime == time20){
            ui->time20Button->setStyleSheet("#time20Button{border-image: url(:/pngs/topMiddleLessGreen.png);}");
            ui->time45Button->setStyleSheet("#time45Button{border-image: url(:/pngs/topMiddleMore.png);}");
            ui->customTimeButton->setStyleSheet("#customTimeButton{border-image: url(:/pngs/topMiddlePlus.png);}");
        }else if(selectedTime == time45){
            ui->time20Button->setStyleSheet("#time20Button{border-image: url(:/pngs/topMiddleLess.png);}");
            ui->time45Button->setStyleSheet("#time45Button{border-image: url(:/pngs/topMiddleMoreGreen.png);}");
            ui->customTimeButton->setStyleSheet("#customTimeButton{border-image: url(:/pngs/topMiddlePlus.png);}");
        }else if(selectedTime == timeCustom){
            ui->time20Button->setStyleSheet("#time20Button{border-image: url(:/pngs/topMiddleLess.png);}");
            ui->time45Button->setStyleSheet("#time45Button{border-image: url(:/pngs/topMiddleMore.png);}");
            ui->customTimeButton->setStyleSheet("#customTimeButton{border-image: url(:/pngs/topMiddlePlusGreen.png);}");
        }

        if(device->getSessionType()->getName() == "Alpha"){
            ui->alphaButton->setStyleSheet("#alphaButton{border-image: url(:/pngs/topMiddleAlphaGreen.png);}");
            ui->betaButton->setStyleSheet("#betaButton{border-image: url(:/pngs/topMiddleBeta1.png);}");
            ui->deltaButton->setStyleSheet("#deltaButton{border-image: url(:/pngs/topMiddleA.png);}");
            ui->thetaButton->setStyleSheet("#thetaButton{border-image: url(:/pngs/topMiddleOmega.png);}");
        }else if (device->getSessionType()->getName() == "Beta 1"){
            ui->alphaButton->setStyleSheet("#alphaButton{border-image: url(:/pngs/topMiddleAlpha.png);}");
            ui->betaButton->setStyleSheet("#betaButton{border-image: url(:/pngs/topMiddleBeta1Green.png);}");
            ui->deltaButton->setStyleSheet("#deltaButton{border-image: url(:/pngs/topMiddleA.png);}");
            ui->thetaButton->setStyleSheet("#thetaButton{border-image: url(:/pngs/topMiddleOmega.png);}");
        }else if (device->getSessionType()->getName() == "Delta"){
            ui->alphaButton->setStyleSheet("#alphaButton{border-image: url(:/pngs/topMiddleAlpha.png);}");
            ui->betaButton->setStyleSheet("#betaButton{border-image: url(:/pngs/topMiddleBeta1.png);}");
            ui->deltaButton->setStyleSheet("#deltaButton{border-image: url(:/pngs/topMiddleAGreen.png);}");
            ui->thetaButton->setStyleSheet("#thetaButton{border-image: url(:/pngs/topMiddleOmega.png);}");
        }else if (device->getSessionType()->getName() == "Theta"){
            ui->alphaButton->setStyleSheet("#alphaButton{border-image: url(:/pngs/topMiddleAlpha.png);}");
            ui->betaButton->setStyleSheet("#betaButton{border-image: url(:/pngs/topMiddleBeta1.png);}");
            ui->deltaButton->setStyleSheet("#deltaButton{border-image: url(:/pngs/topMiddleA.png);}");
            ui->thetaButton->setStyleSheet("#thetaButton{border-image: url(:/pngs/topMiddleOmegaGreen.png);}");
        }

    }else{
        ui->onLight->setStyleSheet("#onLight{border-image: url(:/pngs/onLight.png);}");
        ui->time20Button->setStyleSheet("#time20Button{border-image: url(:/pngs/topMiddleLess.png);}");
        ui->time45Button->setStyleSheet("#time45Button{border-image: url(:/pngs/topMiddleMore.png);}");
        ui->customTimeButton->setStyleSheet("#customTimeButton{border-image: url(:/pngs/topMiddlePlus.png);}");
        ui->alphaButton->setStyleSheet("#alphaButton{border-image: url(:/pngs/topMiddleAlpha.png);}");
        ui->betaButton->setStyleSheet("#betaButton{border-image: url(:/pngs/topMiddleBeta1.png);}");
        ui->deltaButton->setStyleSheet("#deltaButton{border-image: url(:/pngs/topMiddleA.png);}");
        ui->thetaButton->setStyleSheet("#thetaButton{border-image: url(:/pngs/topMiddleOmega.png);}");
        ui->treatmentList->clear();
        ui->customTimeBox->clear();
    }
}

//Reacts to the power button being pressed, turning the device on/off
void MainWindow::powerButton() {
    device->powerButtonPressed();
    setup();
}

//Sets up the Main Window GUI for when the device is on
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

//Reacts to the start button being pressed, attempting to start a treatment
void MainWindow::startButton() {
    setSessionTime();
    device->startTreatment();
}

//Reacts to the history button being pressed, attempting to start a selected recorded treatment
void MainWindow::historyButton() {
    int index = (ui->treatmentList->currentIndex()).row();
    selectedTime = timeCustom;
    device->replayRecording(index);
}

//Drains the device battery by 3%
void MainWindow::drainBatteryBy3() {
    device->drainBattery(3);
}

//Drains the device battery by 10%
void MainWindow::drainBatteryBy10() {
    device->drainBattery(10);
}

//Charges the device battery to full
void MainWindow::chargeBatteryToFull() {
    device->fullCharge();
}

//Reacts to the increase intensity button being pressed,
//attempting to increase the treatment intensity
void MainWindow::increaseIntensity(){
    device->increaseIntensity();
}

//Reacts to the decrease intensity button being pressed,
//attempting to decrease the treatment intensity
void MainWindow::decreaseIntensity(){
    device->decreaseIntensity();
}

//Reacts to the 'Add Treatment To History' checkbox being toggled and sets the device accordingly
void MainWindow::toggleCheckbox(bool checked){
    device->setIsRecording(checked);
}

//Reacts to the 'Attach Device to Skin' dropdown being toggled and sets the device accordingly
void MainWindow::toggleAttachment(const QString& value){
    if(value.toStdString() == "True"){
        device->setTouchingSkin(true);
    }
    else{
        device->setTouchingSkin(false);
    }
}

//Sets the selected treatment time to 20 minutes
void MainWindow::select20MinSession(){
    selectedTime = time20;
}

//Sets the selected treatment time to 45 minutes
void MainWindow::select45MinSession(){
    selectedTime = time45;
}

//Sets the selected treatment time to custom
void MainWindow::selectCustomSession(){
    selectedTime = timeCustom;
}

//Sets the treatment session type to Alpha
void MainWindow::selectAlphaSession(){
    device->setSessionType(new AlphaSession);
}

//Sets the treatment session type to Beta
void MainWindow::selectBetaSession(){
    device->setSessionType(new BetaSession);
}

//Sets the treatment session type to Delta
void MainWindow::selectDeltaSession(){
    device->setSessionType(new DeltaSession);
}

//Sets the treatment session type to Theta
void MainWindow::selectThetaSession(){
    device->setSessionType(new ThetaSession);
}

//Sets the treatment session time to the selected treatment time
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
