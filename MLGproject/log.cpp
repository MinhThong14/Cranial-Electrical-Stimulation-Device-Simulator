#include "log.h"

void log(string message){
    qInfo() << QString::fromStdString(message);
}
