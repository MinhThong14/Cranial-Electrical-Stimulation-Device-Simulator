#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cout<<"hello"<<endl;
    cout<<"hello2"<<endl;
    return a.exec();

}
