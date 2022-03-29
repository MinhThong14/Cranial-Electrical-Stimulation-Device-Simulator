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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QLabel *topRight1;
    QPushButton *downButton;
    QLabel *oasisPro;
    QLabel *topRight2;
    QLabel *topRight3;
    QLabel *topRight4;
    QLabel *topLeft;
    QLabel *topMiddleLess;
    QLabel *topMiddleMore;
    QLabel *topMiddle3h;
    QLabel *topMiddlePlus;
    QLabel *topMiddleMET;
    QLabel *topMiddleSA;
    QLabel *topMiddleA;
    QLabel *topMiddleOmega;
    QLabel *topMiddleAlpha;
    QLabel *topMiddleBeta1;
    QLabel *topMiddleBeta2;
    QLabel *topMiddle100HZ;
    QLabel *tDCS;
    QLabel *bar1;
    QLabel *bar2;
    QLabel *bar3;
    QLabel *bar4;
    QLabel *bar5;
    QLabel *bar6;
    QLabel *bar7;
    QLabel *bar8;
    QPushButton *upButton;
    QLabel *INT;
    QPushButton *checkButton;
    QLabel *bottomLeft;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QFrame(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 800, 600));
        Background->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        Background->setFrameShape(QFrame::StyledPanel);
        Background->setFrameShadow(QFrame::Raised);
        onButton = new QPushButton(Background);
        onButton->setObjectName(QString::fromUtf8("onButton"));
        onButton->setGeometry(QRect(470, 475, 71, 68));
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
        onLight->setGeometry(QRect(488, 462, 35, 18));
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
        topRight1 = new QLabel(Background);
        topRight1->setObjectName(QString::fromUtf8("topRight1"));
        topRight1->setGeometry(QRect(450, 30, 41, 21));
        topRight1->setStyleSheet(QString::fromUtf8("#topRight1\n"
"{\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	border-image: url(:/pngs/topRight1.png);\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}"));
        downButton = new QPushButton(Background);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(380, 480, 61, 51));
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
        oasisPro->setGeometry(QRect(460, 170, 331, 201));
        oasisPro->setStyleSheet(QString::fromUtf8("#oasisPro\n"
"{\n"
"	background-color: transparent;\n"
"	background: none;\n"
"	border-image: url(:/pngs/oasisPro.png);\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}"));
        oasisPro->setPixmap(QPixmap(QString::fromUtf8("../../../V_Code/pngs/oasisPro.png")));
        topRight2 = new QLabel(Background);
        topRight2->setObjectName(QString::fromUtf8("topRight2"));
        topRight2->setGeometry(QRect(500, 30, 41, 20));
        topRight2->setStyleSheet(QString::fromUtf8("#topRight2{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topRight2.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topRight3 = new QLabel(Background);
        topRight3->setObjectName(QString::fromUtf8("topRight3"));
        topRight3->setGeometry(QRect(450, 60, 41, 20));
        topRight3->setStyleSheet(QString::fromUtf8("#topRight3{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topRight3.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topRight4 = new QLabel(Background);
        topRight4->setObjectName(QString::fromUtf8("topRight4"));
        topRight4->setGeometry(QRect(500, 60, 41, 20));
        topRight4->setStyleSheet(QString::fromUtf8("#topRight4{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topRight4.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
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
        topMiddleLess = new QLabel(Background);
        topMiddleLess->setObjectName(QString::fromUtf8("topMiddleLess"));
        topMiddleLess->setGeometry(QRect(190, 80, 31, 31));
        topMiddleLess->setStyleSheet(QString::fromUtf8("#topMiddleLess{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleLess.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleMore = new QLabel(Background);
        topMiddleMore->setObjectName(QString::fromUtf8("topMiddleMore"));
        topMiddleMore->setGeometry(QRect(240, 80, 31, 31));
        topMiddleMore->setStyleSheet(QString::fromUtf8("#topMiddleMore{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleMore.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddle3h = new QLabel(Background);
        topMiddle3h->setObjectName(QString::fromUtf8("topMiddle3h"));
        topMiddle3h->setGeometry(QRect(290, 80, 31, 31));
        topMiddle3h->setStyleSheet(QString::fromUtf8("#topMiddle3h{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddle3h.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddlePlus = new QLabel(Background);
        topMiddlePlus->setObjectName(QString::fromUtf8("topMiddlePlus"));
        topMiddlePlus->setGeometry(QRect(340, 80, 31, 31));
        topMiddlePlus->setStyleSheet(QString::fromUtf8("#topMiddlePlus{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddlePlus.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleMET = new QLabel(Background);
        topMiddleMET->setObjectName(QString::fromUtf8("topMiddleMET"));
        topMiddleMET->setGeometry(QRect(130, 130, 21, 21));
        topMiddleMET->setStyleSheet(QString::fromUtf8("#topMiddleMET{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleMET.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleSA = new QLabel(Background);
        topMiddleSA->setObjectName(QString::fromUtf8("topMiddleSA"));
        topMiddleSA->setGeometry(QRect(170, 130, 21, 21));
        topMiddleSA->setStyleSheet(QString::fromUtf8("#topMiddleSA{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleSA.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleA = new QLabel(Background);
        topMiddleA->setObjectName(QString::fromUtf8("topMiddleA"));
        topMiddleA->setGeometry(QRect(210, 130, 21, 21));
        topMiddleA->setStyleSheet(QString::fromUtf8("#topMiddleA{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleA.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleOmega = new QLabel(Background);
        topMiddleOmega->setObjectName(QString::fromUtf8("topMiddleOmega"));
        topMiddleOmega->setGeometry(QRect(240, 130, 21, 21));
        topMiddleOmega->setStyleSheet(QString::fromUtf8("#topMiddleOmega{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleOmega.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleAlpha = new QLabel(Background);
        topMiddleAlpha->setObjectName(QString::fromUtf8("topMiddleAlpha"));
        topMiddleAlpha->setGeometry(QRect(270, 130, 21, 21));
        topMiddleAlpha->setStyleSheet(QString::fromUtf8("#topMiddleAlpha{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleAlpha.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleBeta1 = new QLabel(Background);
        topMiddleBeta1->setObjectName(QString::fromUtf8("topMiddleBeta1"));
        topMiddleBeta1->setGeometry(QRect(310, 130, 21, 21));
        topMiddleBeta1->setStyleSheet(QString::fromUtf8("#topMiddleBeta1{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleBeta1.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddleBeta2 = new QLabel(Background);
        topMiddleBeta2->setObjectName(QString::fromUtf8("topMiddleBeta2"));
        topMiddleBeta2->setGeometry(QRect(340, 130, 21, 21));
        topMiddleBeta2->setStyleSheet(QString::fromUtf8("#topMiddleBeta2{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddleBeta2.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        topMiddle100HZ = new QLabel(Background);
        topMiddle100HZ->setObjectName(QString::fromUtf8("topMiddle100HZ"));
        topMiddle100HZ->setGeometry(QRect(370, 130, 31, 21));
        topMiddle100HZ->setStyleSheet(QString::fromUtf8("#topMiddle100HZ{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/topMiddle100HZ.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        tDCS = new QLabel(Background);
        tDCS->setObjectName(QString::fromUtf8("tDCS"));
        tDCS->setGeometry(QRect(300, 240, 61, 21));
        tDCS->setStyleSheet(QString::fromUtf8("#tDCS{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/tDCS.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar1 = new QLabel(Background);
        bar1->setObjectName(QString::fromUtf8("bar1"));
        bar1->setGeometry(QRect(210, 500, 141, 21));
        bar1->setStyleSheet(QString::fromUtf8("#bar1{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar1.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar2 = new QLabel(Background);
        bar2->setObjectName(QString::fromUtf8("bar2"));
        bar2->setGeometry(QRect(210, 470, 141, 21));
        bar2->setStyleSheet(QString::fromUtf8("#bar2{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar2.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar3 = new QLabel(Background);
        bar3->setObjectName(QString::fromUtf8("bar3"));
        bar3->setGeometry(QRect(210, 440, 141, 21));
        bar3->setStyleSheet(QString::fromUtf8("#bar3{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar3.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar4 = new QLabel(Background);
        bar4->setObjectName(QString::fromUtf8("bar4"));
        bar4->setGeometry(QRect(210, 410, 141, 21));
        bar4->setStyleSheet(QString::fromUtf8("#bar4{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar4.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar5 = new QLabel(Background);
        bar5->setObjectName(QString::fromUtf8("bar5"));
        bar5->setGeometry(QRect(210, 380, 141, 21));
        bar5->setStyleSheet(QString::fromUtf8("#bar5{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar5.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar6 = new QLabel(Background);
        bar6->setObjectName(QString::fromUtf8("bar6"));
        bar6->setGeometry(QRect(210, 350, 141, 21));
        bar6->setStyleSheet(QString::fromUtf8("#bar6{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar6.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar7 = new QLabel(Background);
        bar7->setObjectName(QString::fromUtf8("bar7"));
        bar7->setGeometry(QRect(210, 320, 141, 21));
        bar7->setStyleSheet(QString::fromUtf8("#bar7{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar7.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        bar8 = new QLabel(Background);
        bar8->setObjectName(QString::fromUtf8("bar8"));
        bar8->setGeometry(QRect(210, 290, 141, 21));
        bar8->setStyleSheet(QString::fromUtf8("#bar8{\n"
"	background-color: transparent;\n"
"	border-image: url(:/pngs/bar8.png);\n"
"	background: none;\n"
"	border: none;\n"
"	background-repeat: none;\n"
"}\n"
"onButton:pressed{\n"
"	border-left: 1px solid rgb(110,144,76);\n"
"}"));
        upButton = new QPushButton(Background);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(380, 410, 61, 51));
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
        INT->setGeometry(QRect(385, 370, 61, 31));
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
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        topRight1->setText(QString());
        downButton->setText(QString());
        oasisPro->setText(QString());
        topRight2->setText(QString());
        topRight3->setText(QString());
        topRight4->setText(QString());
        topLeft->setText(QString());
        topMiddleLess->setText(QString());
        topMiddleMore->setText(QString());
        topMiddle3h->setText(QString());
        topMiddlePlus->setText(QString());
        topMiddleMET->setText(QString());
        topMiddleSA->setText(QString());
        topMiddleA->setText(QString());
        topMiddleOmega->setText(QString());
        topMiddleAlpha->setText(QString());
        topMiddleBeta1->setText(QString());
        topMiddleBeta2->setText(QString());
        topMiddle100HZ->setText(QString());
        tDCS->setText(QString());
        bar1->setText(QString());
        bar2->setText(QString());
        bar3->setText(QString());
        bar4->setText(QString());
        bar5->setText(QString());
        bar6->setText(QString());
        bar7->setText(QString());
        bar8->setText(QString());
        upButton->setText(QString());
        INT->setText(QString());
        checkButton->setText(QString());
        bottomLeft->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
