#pragma once
#include "socketcan_cpp.h"

class CanMessage {
    public:
        CanMessage();
        void SetFrame(int _input);
        scpp::CanFrame GetFrame();
    private:
        scpp::CanFrame frame;
        bool ignition_state{};

        void SetIgnition();
        void SetGearDrive();
        void SetGearRear();
        void SetGearNeutral();
        void SetGearPark();
        void SetPedalPosUp();
        void SetPedalPosDown();
};