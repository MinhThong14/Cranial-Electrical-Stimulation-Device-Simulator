#include "battery.h"

Battery::Battery() {
    power = 100;
    logging = true;
}

void Battery::setLogging(bool doLog) {
    logging = doLog;
}

int Battery::getPower() {
    return power;
}

void Battery::setPower(int amount) {
    if(amount >= 0 && amount <= 100){
        power = amount;
        logPower();
    }
}

//Charges the battery by a provided amount
void Battery::charge(int amount) {
    if(amount < 0){
        return;
    }
    else if((power + amount) > 100){
        power = 100;
    }
    else{
        power += amount;
    }
    logPower();
}

//Charges the battery to full
void Battery::fullCharge() {
    power = 100;
    logPower();
}

//Drains the battery by a provided amount
void Battery::drain(int amount) {
    if(amount < 0){
        return;
    }
    else if((power - amount) < 0){
        power = 0;
    }
    else{
        power -= amount;
    }
    logPower();
}

//Fully drains the battery
void Battery::fullDrain() {
    power = 0;
    logPower();
}

//Checks if the battery is at least a certain amount
bool Battery::isPowerAtLeast(int amount) {
    return (amount <= power);
}

//Checks if the battery is dead
bool Battery::isBatteryDead() {
    return (power <= 0);
}

//Logs the current % charge of the battery
void Battery::logPower() {
    if(logging){
        log(("Battery: " + to_string(power) + "%"));
    }
}
