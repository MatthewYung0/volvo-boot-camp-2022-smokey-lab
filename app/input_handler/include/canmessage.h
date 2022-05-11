#pragma once
#include "socketcan_cpp.h"

#define INPUT_HANDLER_FRAME_ID 0xAAA

#define START_STOP   115
#define GEAR_DRIVE   100
#define GEAR_REAR    114
#define GEAR_NEUTRAL 110
#define GEAR_PARK    112
#define THROTTLE_0   48
#define THROTTLE_10  49
#define THROTTLE_20  50
#define THROTTLE_30  51
#define THROTTLE_40  52
#define THROTTLE_50  53
#define THROTTLE_60  54
#define THROTTLE_70  55
#define THROTTLE_80  56
#define THROTTLE_90  57

class CanMessage {
    public:
        CanMessage();
        void SetFrame(int _input);
        void SetIgnition();
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