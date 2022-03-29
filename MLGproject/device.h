#ifndef DEVICE_H
#define DEVICE_H

#include <log.h>
#include <battery.h>
#include <session.h>
#include <sessiontypes.h>
#include <treatmentdata.h>


class Device
{
public:
    Device();
    ~Device();

private:
    Battery battery;
};

#endif // DEVICE_H
