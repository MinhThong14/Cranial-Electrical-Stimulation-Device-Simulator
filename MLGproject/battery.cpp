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

void Battery::fullCharge() {
    power = 100;
    logPower();
}

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

void Battery::fullDrain() {
    power = 0;
    logPower();
}

bool Battery::isPowerAtLeast(int amount) {
    return (amount <= power);
}

bool Battery::isBatteryDead() {
    return (power <= 0);
}

void Battery::logPower() {
    if(logging){
        log(("Battery: " + to_string(power) + "%"));
    }
}
