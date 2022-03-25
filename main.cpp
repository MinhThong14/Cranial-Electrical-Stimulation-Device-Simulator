#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /////
    //w.setStyleSheet("background-image:url(:button.png)");
    /////


    w.show();
    return a.exec();
}
