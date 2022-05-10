#pragma once
#include "socketcan_cpp.h"

class CanMessage {
    public:
        CanMessage();
        void SetFrame(int _input);
        void SetIgnition();
        // scpp::CanFrame GetFrame();
        scpp::CanFrame frame;
    private:
        bool ignition_state{};

        void SetGearDrive();
        void SetGearRear();
        void SetGearNeutral();
        void SetGearPark();
        void SetPedalPosUp();
        void SetPedalPosDown();
        void SetPedalPos(int _pedal_pos);
};