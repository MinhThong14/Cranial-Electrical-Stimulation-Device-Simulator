#include "log.h"

void log(string message){
    qInfo() << QString::fromStdString(message);
}

void popupAlert(string message){
    QMessageBox alert;
    alert.setDefaultButton(QMessageBox::Close);
    alert.setText(QString::fromStdString(message));
    alert.exec();
}

