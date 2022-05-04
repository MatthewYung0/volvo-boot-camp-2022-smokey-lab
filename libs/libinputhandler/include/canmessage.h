#pragma once
#include "socketcan.h"

class CanMessage {
    public:
        CanMessage();
        void SetFrame(int _input);
        void SetIgnition();
        scpp::CanFrame GetFrame();
    private:
        scpp::CanFrame frame;
        bool ignition_state{};

        void SetGearDrive();
        void SetGearRear();
        void SetGearNeutral();
        void SetGearPark();
        void SetPedalPosUp();
        void SetPedalPosDown();
        void SetPedalPos(int _pedal_pos);
};