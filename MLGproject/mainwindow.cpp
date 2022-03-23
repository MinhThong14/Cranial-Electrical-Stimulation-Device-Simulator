#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    log("Application Started");
    TreatmentData* t = new TreatmentData((60*20), new AlphaSession(), 4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

