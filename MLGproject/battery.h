#ifndef BATTERY_H
#define BATTERY_H

#include <log.h>

class Battery
{
public:
    Battery();
    void update();
    void setLogging(bool doLog);
    int getPower();
    void setPower(int amount);
    void charge(int amount);
    void fullCharge();
    void drain(int amount);
    void fullDrain();
    bool isPowerAtLeast(int amount);
    bool isBatteryDead();
    void logPower();

private:
    int power;
    bool logging;
};

#endif // BATTERY_H
