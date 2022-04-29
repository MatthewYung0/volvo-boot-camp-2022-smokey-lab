#include "Gearbox.h"

class Gearbox {
    private:
    int currentGear;

    public:
    Gearbox(){
        currentGear = 0;
    }
    ~Gearbox();

    bool checkGear(int gear)
    {
        // -1 gear for reverse
        // 0 gear for neutral
        // 1 - 6 for driving
        return gear > -2 && gear < 7;
    }

    int getGear() {
        return currentGear;
    }

    void setGear(int gear) {
        if (checkGear(gear)) {
            this->currentGear = gear;
        }
    }
};