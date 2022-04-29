#pragma once

#include <iostream>

class Gearbox {
    private:
    int currentGear;

    public:
    Gearbox();
    ~Gearbox();

    bool checkGear(int gear);
    int getGear();
    void setGear(int gear);
};