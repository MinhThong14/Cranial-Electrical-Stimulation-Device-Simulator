#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"


#define MINIMUM_BATTERY_LEVEL 0
#define MAXIMUM_BATTERY_LEVEL 100

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setFixedSize(580, 550);

    device = new Device();

    enableDevice(false);

    // Connect UI elements to functions
    connect(ui->freq05hz, &QRadioButton::clicked, this, &MainWindow::changeFrequency);
    connect(ui->freq77hz, &QRadioButton::clicked, this, &MainWindow::changeFrequency);
    connect(ui->freq100hz, &QRadioButton::clicked, this, &MainWindow::changeFrequency);
    connect(ui->waveAlpha, &QRadioButton::clicked, this, &MainWindow::changeWaveform);
    connect(ui->waveBeta, &QRadioButton::clicked, this, &MainWindow::changeWaveform);
    connect(ui->waveGamma, &QRadioButton::clicked, this, &MainWindow::changeWaveform);
    connect(ui->powerButton, &QPushButton::released, this, &MainWindow::pressPowerButton);
    connect(ui->chargeDeviceButton, &QPushButton::released, this, &MainWindow::chargeDeviceToFull);
    connect(ui->batteryBar, &QProgressBar::valueChanged, this, &MainWindow::displayBatteryText);
    connect(ui->drainBattery10, &QPushButton::released, this, &MainWindow::manuallyDecreaseBattery);
    connect(ui->drainBattery1, &QPushButton::released, this, &MainWindow::manuallyDecreaseBattery);
    connect(ui->timeButton, &QPushButton::released, this, &MainWindow::timeButtonPressed);
    connect(ui->upButton, &QPushButton::released, this, &MainWindow::upButtonPressed);
    connect(ui->downButton, &QPushButton::released, this, &MainWindow::downButtonPressed);
    connect(ui->intensityButton, &QPushButton::released, this, &MainWindow::intensityPressed);
    connect(ui->inContactDropdown, &QComboBox::currentTextChanged, this, &MainWindow::toggleSkinInContact);
    connect(ui->exceedCurrentButton, &QPushButton::released, this, &MainWindow::exceedDeviceCurrent);
    connect(ui->recordCheckBox, &QCheckBox::released, this, &MainWindow::recordButtonPressed);
    connect(ui->historyButton, &QPushButton::released, this, &MainWindow::historyPressed);
    connect(ui->fastForwardButton, &QPushButton::released, this, &MainWindow::fastForwardPressed);
    connect(ui->startButton, &QPushButton::released, this, &MainWindow::startButtonClicked);
    connect(ui->fixCurrentButton, &QPushButton::released, this, &MainWindow::fixCurrent);

    // Initialize first states of UI elements
    ui->freq05hz->setChecked(true);
    ui->waveAlpha->setChecked(true);
    ui->inContactDropdown->setCurrentText(device->getIsInContact() ? "True" : "False");
    ui->batteryBar->setMinimum(MINIMUM_BATTERY_LEVEL);
    ui->batteryBar->setMaximum(MAXIMUM_BATTERY_LEVEL);
    ui->batteryBar->setValue(MAXIMUM_BATTERY_LEVEL);
    ui->batteryLabel->setText(QString::number(device->getPowerLevel()));
    ui->treatmentListWidget->setDisabled(true);
    ui->poweredBox->setChecked(true);

    ui->timerGroup->setStyleSheet(":disabled { color: black }");
    ui->timerGroup->setDisabled(true);
    updateTimerSelect();

    resetWindowVariables();

    // Initialize QTimer to drain battery on use
    connect(batteryTimer, &QTimer::timeout, this, &MainWindow::decreaseBattery);
    batteryTimer->start(5000);

    connect(lcdTimer, &QTimer::timeout, this, &MainWindow::decreaseTime);
    connect(currentLevelTimer, &QTimer::timeout, this, &MainWindow::currentExceeded);
    connect(inUse30sTimer, &QTimer::timeout, this, &MainWindow::check30Sec);
    connect(skinTimer, &QTimer::timeout, this, &MainWindow::padsFellProtocol);

    lcdTimer->start(1000);
    currentLevelTimer->start(1000);
    skinTimer->start(1000);
    inUse30sTimer->start(1000);

    lcdTimer->stop();
    currentLevelTimer->stop();
    skinTimer->stop();
    inUse30sTimer->stop();

    ui->poweredBox->setEnabled(false);
    ui->fixCurrentButton->setEnabled(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete device;
}

//this function will start the treatment.
void MainWindow::startButtonClicked(){
    if(device->getIsInContact()){ //make sure that the probes are attached to the skin
        startTimerProtocol();
        device->startTreatment();
        ui->lcdNumber->display(device->getCurrentTimeCycle());
    }

    //if no probes are detected then it will spit out an error message.
    else
        showAlert("Treatment can't start. Attach probes to skin");
}

//this function will fix  the current value. This is for the sake of simplicity for the TA. You're welcome.
void MainWindow::fixCurrent(){
    int currentIntensity = 300;
    ui->intensityBar->setValue(currentIntensity/50);
    device->setCurrent(currentIntensity);
    ui->powerButton->setEnabled(true);
    device->startTreatment(false);
}

//This function handles what to do if it detects a change in the skin contact.
void MainWindow::toggleSkinInContact(QString value)
{
    device->setIsInContact(value == "True");
    if(!device->getIsInContact())
    {
        skinTimer->start();
        ui->poweredBox->setChecked(false);
    }
    else
    {
        skinTimer->stop();
        skin5sTimerIndicator = 0;
        ui->poweredBox->setChecked(true);
    }
}

//if pads fell from earlobs thenn this function is called every second for a total of 5 seconds.
void MainWindow::padsFellProtocol(){
    if (!device->getTreatmentStarted())
        return;

    //this if statement is triggered when pads have fallen for 5 seconds.
    if(++skin5sTimerIndicator == 5)
    {
        skinTimer->stop();
        enableDevice(false);
        showAlert("Electrodes lost contact with your skin. Turning off the device.");
    }

    // Displaying to console to observe
    qWarning() << "Checking 5s timer after losing skin contact: " << skin5sTimerIndicator;
}

//This function displays a alert message.
void MainWindow::showAlert(QString message)
{
    QMessageBox alert;
    alert.setDefaultButton(QMessageBox::Close);
    alert.setText(message);
    alert.exec();
}

//This function updates the timer buttons as well as the lcd value.
void MainWindow::updateTimerSelect()
{
    switch(device->getCurrentTimeCycle()) {
        case 20:
            ui->timer20Radio->setChecked(true);
            break;
        case 40:
            ui->timer40Radio->setChecked(true);
            break;
        default:
            ui->timer60Radio->setChecked(true);
    }
}

void MainWindow::recordButtonPressed(){
    // reset 30s timer
    timer30sIndicator = 0;

    device->toggleRecording();
    ui->recordCheckBox->setChecked(device->isRecording());
}

void MainWindow::recordTreatment(){
    if (!device->isRecording())
        return;

    device->recordCurrentTreatment();
    ui->treatmentListWidget->addItem("Treatment " + QString::number(device->getNumberOfRecordedTreatment()));
}

//This function handles the intensity button when pressed. It will disable the uneccessary buttons and save the new intensity.
void MainWindow::intensityPressed(){
    // reset 30s timer
    timer30sIndicator = 0;

    if(intensityButtonClicked)
    {
        enableAllButtons();
        intensityButtonClicked = false;
        device->setCurrent(ui->intensityBar->value()*50);
    }
    else
    {
        disableAllButtonsExcept("intensityButton");
        ui->upButton->setEnabled(true);
        ui->downButton->setEnabled(true);
        intensityButtonClicked = true;
    }
}

//this function handles when the up button is pressed.
void MainWindow::upButtonPressed() {
    // reset 30s timer
    timer30sIndicator = 0;

    int time = device->getCurrentTimeCycle();
    //if statement to see what type of context the up button serves. In this case it serves for the timer selection.
    if(timeButtonClicked)
    {
        device->setTimeCycle(time == 60 ? 20 : time + 20);
        updateTimerSelect();
    }
    //else it serves for the intensity, therefore it manipulates the intensity values.
    else if(intensityButtonClicked)
    {
        int currentIntensity = ui->intensityBar->value()*50;
        if(currentIntensity == 500)
        {
            ui->intensityBar->setValue(50/50);
        }
        else
        {
            currentIntensity = currentIntensity + 50;
            ui->intensityBar->setValue(currentIntensity/50);
        }
    }
}

//this function handles when the down buttonis pressed.
void MainWindow::downButtonPressed() {
    // reset 30s timer
    timer30sIndicator = 0;

    int time = device->getCurrentTimeCycle();
    //if the context is about time, then the down button will change the time value.
    if(timeButtonClicked)
    {
        device->setTimeCycle(time == 20 ? 60 : time - 20);
        updateTimerSelect();
    }

    //else the context is intensity and it will control the intenisty.
    else if(intensityButtonClicked){
        int currentIntensity = ui->intensityBar->value() * 50;

        if(currentIntensity == 0)
            ui->intensityBar->setValue(400/50);
        else if (currentIntensity == 100)
            ui->intensityBar->setValue(500/50);
        else if (currentIntensity == 50)
            ui->intensityBar->setValue(450/50);
        else
        {
            currentIntensity = currentIntensity - 100;
            ui->intensityBar->setValue(currentIntensity/50);
        }
    }
}

// This function controlls the time value.
void MainWindow::timeButtonPressed(){
    // reset 30s timer
    timer30sIndicator = 0;

    // if it has already been clicked then save the final values and re-enable all buttons.
    if(timeButtonClicked)
    {
        enableAllButtons();
        timeButtonClicked = false;
    }
    // else this means it has been clicked for the first time which means the user is trying to manipulate the timer.
    // Disable the buttons which are not needed and give the context to what is being manipulated to device.
    else
    {
        timeButtonClicked = true;
        timerReachedZero = false;
        disableAllButtonsExcept("timeButton");
        ui->upButton->setEnabled(true);
        ui->downButton->setEnabled(true);
    }
}

// This function controls the history button
void MainWindow::historyPressed()
{
    // reset 30s timer
    timer30sIndicator = 0;

    // this means that the history button has already been clicked and manipulation of data is over. therefore we need to save the state.
    if(historyButtonClicked)
    {
        enableAllButtons();
        ui->treatmentListWidget->setEnabled(false);

        int index = ui->treatmentListWidget->currentRow(); //get the index of the chosen history.
        if (index >= 0)
        {
            device->replayRecordedTreatment(index); // tell the device to look for th egiven index to find the treatement.
            refreshAllButtonBasedOnCurrentTreatment(); // call functions to set the values
        }
    }

    else
    {
        timerReachedZero = false;
        ui->treatmentListWidget->setEnabled(true);
        disableAllButtonsExcept("historyButton");
    }

    historyButtonClicked = !historyButtonClicked;
}

//This is for the TA, I mean you're welcome.
void MainWindow::fastForwardPressed()
{
    if (ui->lcdNumber->value() > 2)
        ui->lcdNumber->display(2);
}

//This function starts the countdown process.
void MainWindow::startTimerProtocol()
{
    //if we lose contact display an error message.
    if (!device->getIsInContact())
    {
        lcdTimer->stop();
        showAlert("Ear clips are not in contact with your skin.\nTreatment is paused until skin is in contact.");
    }
    //if timer isn't 0 then start the decrease timer function every 1 second. And tell the device treatment has started.
    else if (!timerReachedZero)
    {
        lcdTimer->start();
        device->startTreatment();
    }
    //this means we are done
    else
    {
        lcdTimer->stop();
        recordTreatment();
        enableDevice(false);
    }
}

//This handles the change of time for the lcd number. This function gets called every second and takes a second away from the timer display.
void MainWindow::decreaseTime(){
    int remainTime = ui->lcdNumber->value();
    if(remainTime == 0)
    {
        device->startTreatment(false);
        timerReachedZero = true;
        startTimerProtocol();
        return;
    }
    ui->lcdNumber->display(--remainTime);
}

//this basically enables all buttons. No explanation needed really...
void MainWindow::enableAllButtons(){
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();

    for (int i = 0; i < allButtons.size(); i++)
       allButtons[i]->setEnabled(true);
}

//this function takes a string of a buttons name as an input and disables every button except that input button.
void MainWindow::disableAllButtonsExcept(QString button){
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();

    for (int i = 0; i < allButtons.size(); i++)
    {
        if(allButtons[i]->objectName() != button)
            allButtons[i]->setDisabled(true);
    }
    importantButtonsEnabled(); // re-enables the user buttons such as charge device and all that.
}

//this re-enabled the buttons that are needed for testing purposes for TA
void MainWindow::importantButtonsEnabled(){
    ui->powerButton->setEnabled(true);
    ui->exceedCurrentButton->setEnabled(true);
    ui->chargeDeviceButton->setEnabled(true);
    ui->fastForwardButton->setEnabled(true);
    ui->drainBattery1->setEnabled(true);
    ui->drainBattery10->setEnabled(true);
    ui->inContactDropdown->setEnabled(true);
    ui->inContactDropdown->setEnabled(true);
    ui->fixCurrentButton->setEnabled(true);
//    lcdTimer->setInterval(0);
    ui->recordCheckBox->setEnabled(true);
}

//This function handles when the power button is pressed.
void MainWindow::pressPowerButton()
{
    // reset 30s timer
    timer30sIndicator = 0;

    //if the device is off then turn it on.
    if (!device->getIsOn())
    {
        enableDevice(true);

        //30 second (minute) timer starts. It will call check30sec function every second.
        if(!device->getTreatmentStarted())
            inUse30sTimer->start();
    }
    //this means the device is off, therefore turn it on.
    else
    {
        enableDevice(false);
        device->startTreatment(false);
        inUse30sTimer->stop();
    }
}

//This function will be called second from pressPowerButton.
void MainWindow::check30Sec(){
    //qInfo() << "I got called";
    // If statement to see if a treatment has started.
    // If not then add 1 to the indicator, otherwise, reset the timer
    if(!device->getTreatmentStarted()){

        timer30sIndicator++;
    }
    else{
        timer30sIndicator = 0;

    }

    // Displaying to console to observe
    qWarning() << "Checking 30s timer: " << timer30sIndicator;

    // If the value is at 30 then this means 30 seconds has gone by without a treatement while th edevice is powered on.
    // We tell the user we are shutting down and then disable the device.
    if(timer30sIndicator == 30){
        inUse30sTimer->stop();
        enableDevice(false);
        showAlert("Treatment not started for 30 seconds. Device will shut down.");
    }
}

// This just change sthe waveform.
void MainWindow::changeWaveform() {
    // reset 30s timer
    timer30sIndicator = 0;

    Waveform waveform = ALPHA;
    if (ui->waveBeta->isChecked())
        waveform = BETA;
    else if (ui->waveGamma->isChecked())
        waveform = GAMMA;

    device->changeCurrentWaveform(waveform);
}

// This changes the frequency
void MainWindow::changeFrequency()
{
    // reset 30s timer
    timer30sIndicator = 0;

    float frequency = 0.5;
    if (ui->freq77hz->isChecked())
        frequency = 77;
    else if (ui->freq100hz->isChecked())
        frequency = 100;

    device->changeCurrentFrequency(frequency);
}

// This function is called when we want to enable or disable the device. If true then we want to enable, if false we want to disable.
void MainWindow::enableDevice(bool enable)
{
    // Don't let the device turn on if power is under 3%. Go charge it.
    if (enable && device->getPowerLevel() < 3)
        return;

    device->setIsOn(enable);

    ui->frequencyWidget->setEnabled(enable);
    ui->waveformWidget->setEnabled(enable);

    if (!enable)
    {
        skinTimer->stop();
        inUse30sTimer->stop();
        currentLevelTimer->stop();
        batteryTimer->stop();
        lcdTimer->stop();
    }
    else {
        currentLevelTimer->start();
        batteryTimer->start(5000);
    }



    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();

    for (int i = 0; i < allButtons.size(); i++)
    {
        if (allButtons[i] == ui->powerButton || allButtons[i] == ui->chargeDeviceButton)
            continue;
        //enable all buttons which are disabled and disable the buttons which are enabled.
        allButtons[i]->setDisabled(!enable);
        allButtons[i]->setEnabled(enable);
    }

    importantButtonsEnabled();
    ui->lcdNumber->display(0);

    if (!enable)
        resetWindowVariables();
}

//i mean it charges the device ya know
void MainWindow::chargeDeviceToFull()
{
    device->setPowerLevel(MAXIMUM_BATTERY_LEVEL);
    ui->batteryBar->setValue(device->getPowerLevel());
}

//decrease battery function.
void MainWindow::decreaseBattery()
{
    if (device->getIsOn() == false)
        return;

    device->drainBattery(); //call the drain battery from device.
    ui->batteryBar->setValue(device->getPowerLevel());

    QMessageBox alert;
    alert.setDefaultButton(QMessageBox::Close);

    //if power is at 5% then it display a warning message.
    if (device->getPowerLevel() == 5)
        showAlert("Device is at 5%. It will shut off at 2%");

    //else if the device is at 2% then it shuts off.
    else if (device->getPowerLevel() == 2)
    {
        showAlert("Device is at 2%. It will shut off");

        device->setIsOn(false);
        enableDevice(false);
    }
}

//This just manually decrease the battery for the TA.
void MainWindow::manuallyDecreaseBattery()
{
    int decrement = sender()->objectName() == "drainBattery1" ? 1 : 10;
    int power = device->getPowerLevel();
    device->drainBatteryBy(decrement >= power || power <= 3 ? 0 : decrement);
    ui->batteryBar->setValue(device->getPowerLevel());
}

void MainWindow::displayBatteryText()
{
    ui->batteryLabel->setText(QString::number(device->getPowerLevel()));
}

void MainWindow::exceedDeviceCurrent()
{
    device->setCurrent(700);
}

void MainWindow::currentExceeded()
{
    //this checks to see that the device is on and the that the current is too high. If it is, then it disabled the device.
    if (device->getTreatmentCurrent() >= 700 && device->getIsOn()){
        enableDevice(false);
    }
}

//Reset our values to default.
void MainWindow::resetWindowVariables()
{
    timeButtonClicked = false;
    intensityButtonClicked = false;
    historyButtonClicked = false;
    timerReachedZero = false;
    ui->treatmentListWidget->clearSelection();
}

//Resets our values back to what we want.
void MainWindow::refreshAllButtonBasedOnCurrentTreatment()
{
    if (device->getCurrentFrequency() == 0.5)
        ui->freq05hz->setChecked(true);
    else if (device->getCurrentFrequency() == 77)
        ui->freq77hz->setChecked(true);
    else
        ui->freq100hz->setChecked(true);

    if (device->getCurrentWaveform() == ALPHA)
        ui->waveAlpha->setChecked(true);
    else if (device->getCurrentWaveform() == BETA)
        ui->waveBeta->setChecked(true);
    else
        ui->waveGamma->setChecked(true);

    updateTimerSelect();
    ui->intensityBar->setValue(device->getTreatmentCurrent()/50);
}
