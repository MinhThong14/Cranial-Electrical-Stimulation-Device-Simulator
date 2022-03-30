#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <QDebug>
#include <QMessageBox>
#include <QString>

using namespace std;

void log(string message);
void popupAlert(string message);

#endif // LOG_H
