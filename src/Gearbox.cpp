#include "Gearbox.h"

int currentGear;

Gearbox::Gearbox()
{
    currentGear = 0;
};
Gearbox::Gearbox(int currentGear) : currentGear(currentGear){};
Gearbox::~Gearbox(){};

bool checkGear(int gear)
{
    // -1 gear for reverse
    // 0 gear for neutral
    // 1 - 6 for driving
    return gear > -2 && gear < 7;
}

int getGear()
{
    return currentGear;
}

void Gearbox::setGear(int gear)
{
    if (checkGear(gear))
    {
        this->currentGear = gear;
    }
}