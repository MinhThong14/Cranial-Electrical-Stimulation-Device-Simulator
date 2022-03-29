#include "device.h"

Device::Device()
{

}

Device::~Device()
{

}

void Device::update()
{
    battery.drain(1);
}
