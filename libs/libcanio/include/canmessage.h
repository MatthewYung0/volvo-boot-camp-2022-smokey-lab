#pragma once
#include "socketcan_cpp.h"

class CanMessage {
    public:
        CanMessage();
        void SetFrame(int _input);
        void ResetFrame();
        scpp::CanFrame GetFrame();
    private:
        scpp::CanFrame frame;

        void SetIgnition();
        void SetGearDrive();
        void SetGearRear();
        void SetGearNeutral();
        void SetGearPark();
        void SetPedalPosUp();
        void SetPedalPosDown();
        void SetPedalPos(int _pedal_pos);
};