/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *Background;
    QPushButton *onButton;
    QLabel *canada;
    QLabel *onLight;
    QLabel *mindAlive;
    QPushButton *downButton;
    QLabel *oasisPro;
    QLabel *topLeft;
    QPushButton *upButton;
    QLabel *INT;
    QPushButton *checkButton;
    QLabel *bottomLeft;
    QLCDNumber *lcdNumber;
    QListWidget *historyWidget;
    QPushButton *alphaButton;
    QPushButton *betaButton;
    QPushButton *deltaButton;
    QPushButton *thetaButton;
    QPushButton *time20Button;
    QPushButton *time45Button;
    QLabel *customTimeLabel;
    QLCDNumber *intensityCounter;
    QProgressBar *batteryBar;
    QLabel *batteryLabel;
    QPushButton *customTimeButton;
    QLineEdit *customTimeBox;
    QPushButton *historyButton;
    QListWidget *treatmentList;
    QFrame *Background_2;
    QPushButton *chargeDeviceButton;
    QLabel *background2Label;
    QLabel *drainBatteryLabel;
    QPushButton *drainBattery1;
    QPushButton *drainBattery2;
    QLabel *attachToSkinLabel;
    QComboBox *contackSkinDropbox;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 791, 600));
        Background->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        onButton = new QPushButton(Background);
        onButton->setObjectName(QString::fromUtf8("onButton"));
        onButton->setGeometry(QRect(490, 470, 71, 68));
        onButton->setStyleSheet(QString::fromUtf8("#onButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/onButton.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        canada = new QLabel(Background);
        canada->setObjectName(QString::fromUtf8("canada"));
        canada->setGeometry(QRect(630, 480, 161, 51));
        canada->setStyleSheet(QString::fromUtf8("#canada\n"
"{\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	border-image: url(:/pngs/canada.png);\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}"));
        onLight = new QLabel(Background);
        onLight->setObjectName(QString::fromUtf8("onLight"));
        onLight->setGeometry(QRect(509, 458, 35, 18));
        onLight->setStyleSheet(QString::fromUtf8("#onLight{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/onLight.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        mindAlive = new QLabel(Background);
        mindAlive->setObjectName(QString::fromUtf8("mindAlive"));
        mindAlive->setGeometry(QRect(610, 20, 181, 41));
        mindAlive->setStyleSheet(QString::fromUtf8("#mindAlive\n"
"{\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	border-image: url(:/pngs/mindAlive.png);\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}"));
        downButton = new QPushButton(Background);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(400, 480, 61, 51));
        downButton->setStyleSheet(QString::fromUtf8("#downButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/downButton.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"downButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        oasisPro = new QLabel(Background);
        oasisPro->setObjectName(QString::fromUtf8("oasisPro"));
        oasisPro->setGeometry(QRect(480, 200, 301, 181));
        oasisPro->setStyleSheet(QString::fromUtf8("#oasisPro\n"
"{\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	border-image: url(:/pngs/oasisPro.png);\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}"));
        oasisPro->setPixmap(QPixmap(QString::fromUtf8("../../../../../V_Code/pngs/oasisPro.png")));
        topLeft = new QLabel(Background);
        topLeft->setObjectName(QString::fromUtf8("topLeft"));
        topLeft->setGeometry(QRect(20, 50, 31, 31));
        topLeft->setStyleSheet(QString::fromUtf8("#topLeft{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topLeft.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        upButton = new QPushButton(Background);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(400, 410, 61, 51));
        upButton->setStyleSheet(QString::fromUtf8("#upButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/upButton.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"downButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        INT = new QLabel(Background);
        INT->setObjectName(QString::fromUtf8("INT"));
        INT->setGeometry(QRect(400, 360, 61, 31));
        INT->setStyleSheet(QString::fromUtf8("#INT{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/INT.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        checkButton = new QPushButton(Background);
        checkButton->setObjectName(QString::fromUtf8("checkButton"));
        checkButton->setGeometry(QRect(70, 490, 61, 51));
        checkButton->setStyleSheet(QString::fromUtf8("#checkButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/checkButton.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"downButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bottomLeft = new QLabel(Background);
        bottomLeft->setObjectName(QString::fromUtf8("bottomLeft"));
        bottomLeft->setGeometry(QRect(10, 450, 41, 31));
        bottomLeft->setStyleSheet(QString::fromUtf8("#bottomLeft{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bottomLeft.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        lcdNumber = new QLCDNumber(Background);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setEnabled(false);
        lcdNumber->setGeometry(QRect(560, 100, 161, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans Adlam"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setLineWidth(2);
        lcdNumber->setMidLineWidth(1);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Outline);
        historyWidget = new QListWidget(Background);
        historyWidget->setObjectName(QString::fromUtf8("historyWidget"));
        historyWidget->setGeometry(QRect(10, 180, 161, 231));
        historyWidget->setFrameShape(QFrame::Box);
        historyWidget->setFrameShadow(QFrame::Sunken);
        historyWidget->setMidLineWidth(1);
        alphaButton = new QPushButton(Background);
        alphaButton->setObjectName(QString::fromUtf8("alphaButton"));
        alphaButton->setGeometry(QRect(200, 130, 21, 20));
        alphaButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleAlpha.png);"));
        betaButton = new QPushButton(Background);
        betaButton->setObjectName(QString::fromUtf8("betaButton"));
        betaButton->setGeometry(QRect(250, 130, 21, 23));
        betaButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleBeta1.png);"));
        deltaButton = new QPushButton(Background);
        deltaButton->setObjectName(QString::fromUtf8("deltaButton"));
        deltaButton->setGeometry(QRect(300, 130, 21, 20));
        deltaButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleA.png);"));
        thetaButton = new QPushButton(Background);
        thetaButton->setObjectName(QString::fromUtf8("thetaButton"));
        thetaButton->setGeometry(QRect(350, 130, 21, 20));
        thetaButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleOmega.png);"));
        time20Button = new QPushButton(Background);
        time20Button->setObjectName(QString::fromUtf8("time20Button"));
        time20Button->setGeometry(QRect(200, 70, 31, 31));
        time20Button->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleLess.png);"));
        time45Button = new QPushButton(Background);
        time45Button->setObjectName(QString::fromUtf8("time45Button"));
        time45Button->setGeometry(QRect(250, 70, 31, 31));
        time45Button->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddleMore.png);"));
        customTimeLabel = new QLabel(Background);
        customTimeLabel->setObjectName(QString::fromUtf8("customTimeLabel"));
        customTimeLabel->setGeometry(QRect(350, 40, 81, 21));
        customTimeLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        customTimeLabel->setAlignment(Qt::AlignCenter);
        intensityCounter = new QLCDNumber(Background);
        intensityCounter->setObjectName(QString::fromUtf8("intensityCounter"));
        intensityCounter->setEnabled(false);
        intensityCounter->setGeometry(QRect(220, 430, 161, 81));
        intensityCounter->setFont(font);
        intensityCounter->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(233, 232, 5);"));
        intensityCounter->setFrameShape(QFrame::Box);
        intensityCounter->setLineWidth(2);
        intensityCounter->setMidLineWidth(1);
        intensityCounter->setSmallDecimalPoint(false);
        intensityCounter->setSegmentStyle(QLCDNumber::Outline);
        batteryBar = new QProgressBar(Background);
        batteryBar->setObjectName(QString::fromUtf8("batteryBar"));
        batteryBar->setGeometry(QRect(190, 270, 271, 31));
        batteryBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 4px solid grey;\n"
"     border-radius: 5px;\n"
"     background-color: #000000;\n"
" }\n"
"\n"
" QProgressBar::chunk {\n"
"     background-color: #7bcbc0;\n"
" }"));
        batteryBar->setValue(24);
        batteryBar->setTextVisible(false);
        batteryBar->setTextDirection(QProgressBar::TopToBottom);
        batteryLabel = new QLabel(Background);
        batteryLabel->setObjectName(QString::fromUtf8("batteryLabel"));
        batteryLabel->setGeometry(QRect(280, 310, 91, 31));
        batteryLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 75 18pt \"Noto Sans\";"));
        batteryLabel->setAlignment(Qt::AlignCenter);
        customTimeButton = new QPushButton(Background);
        customTimeButton->setObjectName(QString::fromUtf8("customTimeButton"));
        customTimeButton->setGeometry(QRect(300, 70, 31, 31));
        customTimeButton->setStyleSheet(QString::fromUtf8("border-image: url(:/pngs/topMiddlePlus.png);"));
        customTimeBox = new QLineEdit(Background);
        customTimeBox->setObjectName(QString::fromUtf8("customTimeBox"));
        customTimeBox->setGeometry(QRect(360, 70, 61, 31));
        customTimeBox->setStyleSheet(QString::fromUtf8("border: 2px solid white;\n"
"border-radius: 5px;\n"
"border-color: #fdfdfc;\n"
"color: #fdfdfc;"));
        historyButton = new QPushButton(Background);
        historyButton->setObjectName(QString::fromUtf8("historyButton"));
        historyButton->setGeometry(QRect(70, 420, 61, 51));
        historyButton->setStyleSheet(QString::fromUtf8("#historyButton{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/hButton.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"downButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        treatmentList = new QListWidget(Background);
        treatmentList->setObjectName(QString::fromUtf8("treatmentList"));
        treatmentList->setGeometry(QRect(20, 190, 141, 211));
        treatmentList->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Background_2 = new QFrame(centralwidget);
        Background_2->setObjectName(QString::fromUtf8("Background_2"));
        Background_2->setGeometry(QRect(810, 0, 291, 291));
        Background_2->setLayoutDirection(Qt::RightToLeft);
        Background_2->setStyleSheet(QString::fromUtf8(""));
        Background_2->setFrameShape(QFrame::StyledPanel);
        Background_2->setFrameShadow(QFrame::Raised);
        chargeDeviceButton = new QPushButton(Background_2);
        chargeDeviceButton->setObjectName(QString::fromUtf8("chargeDeviceButton"));
        chargeDeviceButton->setGeometry(QRect(10, 70, 271, 41));
        background2Label = new QLabel(Background_2);
        background2Label->setObjectName(QString::fromUtf8("background2Label"));
        background2Label->setGeometry(QRect(10, 10, 281, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Sans Adlam"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        background2Label->setFont(font1);
        drainBatteryLabel = new QLabel(Background_2);
        drainBatteryLabel->setObjectName(QString::fromUtf8("drainBatteryLabel"));
        drainBatteryLabel->setGeometry(QRect(10, 140, 81, 31));
        drainBattery1 = new QPushButton(Background_2);
        drainBattery1->setObjectName(QString::fromUtf8("drainBattery1"));
        drainBattery1->setGeometry(QRect(100, 140, 80, 25));
        drainBattery2 = new QPushButton(Background_2);
        drainBattery2->setObjectName(QString::fromUtf8("drainBattery2"));
        drainBattery2->setGeometry(QRect(200, 140, 80, 25));
        attachToSkinLabel = new QLabel(Background_2);
        attachToSkinLabel->setObjectName(QString::fromUtf8("attachToSkinLabel"));
        attachToSkinLabel->setGeometry(QRect(10, 200, 141, 31));
        attachToSkinLabel->setLayoutDirection(Qt::LeftToRight);
        contackSkinDropbox = new QComboBox(Background_2);
        contackSkinDropbox->addItem(QString());
        contackSkinDropbox->addItem(QString());
        contackSkinDropbox->setObjectName(QString::fromUtf8("contackSkinDropbox"));
        contackSkinDropbox->setGeometry(QRect(160, 200, 72, 25));
        contackSkinDropbox->setLayoutDirection(Qt::LeftToRight);
        checkBox = new QCheckBox(Background_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 250, 211, 23));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        checkBox->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Noto Sans"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        checkBox->setFont(font2);
        checkBox->setLayoutDirection(Qt::LeftToRight);
        checkBox->setAutoFillBackground(false);
        checkBox->setStyleSheet(QString::fromUtf8("font: 9pt \"Noto Sans\";"));
        checkBox->setChecked(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        onButton->setText(QString());
        canada->setText(QString());
        onLight->setText(QString());
        mindAlive->setText(QString());
        downButton->setText(QString());
        oasisPro->setText(QString());
        topLeft->setText(QString());
        upButton->setText(QString());
        INT->setText(QString());
        checkButton->setText(QString());
        bottomLeft->setText(QString());
        alphaButton->setText(QString());
        betaButton->setText(QString());
        deltaButton->setText(QString());
        thetaButton->setText(QString());
        time20Button->setText(QString());
        time45Button->setText(QString());
        customTimeLabel->setText(QApplication::translate("MainWindow", "Set Time", nullptr));
        batteryLabel->setText(QApplication::translate("MainWindow", "Battery", nullptr));
        customTimeButton->setText(QString());
        customTimeBox->setText(QString());
        historyButton->setText(QString());
        chargeDeviceButton->setText(QApplication::translate("MainWindow", "Charge Device To Full of Battery ", nullptr));
        background2Label->setText(QApplication::translate("MainWindow", "Device Internal Simulator", nullptr));
        drainBatteryLabel->setText(QApplication::translate("MainWindow", "Drain Battery", nullptr));
        drainBattery1->setText(QApplication::translate("MainWindow", "-3%", nullptr));
        drainBattery2->setText(QApplication::translate("MainWindow", "-10%", nullptr));
        attachToSkinLabel->setText(QApplication::translate("MainWindow", "Attach Device to Skin:", nullptr));
        contackSkinDropbox->setItemText(0, QApplication::translate("MainWindow", "True", nullptr));
        contackSkinDropbox->setItemText(1, QApplication::translate("MainWindow", "False", nullptr));

        checkBox->setText(QApplication::translate("MainWindow", "Add Treatment To History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
