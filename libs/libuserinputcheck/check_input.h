#define START_STOP 115
#define GEAR_DRIVE 100
#define GEAR_REAR 114
#define GEAR_NEUTRAL 110
#define GEAR_PARK 112
#define THROTTLE_0 48
#define THROTTLE_10 49
#define THROTTLE_20 50
#define THROTTLE_30 51
#define THROTTLE_40 52
#define THROTTLE_50 53
#define THROTTLE_60 54
#define THROTTLE_70 55
#define THROTTLE_80 56
#define THROTTLE_90 57

#define INPUT_HANDLER_FRAME_ID 0xAAA

#define APPLICATION_ON_OFF

namespace canData {
    enum DataElement {
        ignition = 0,
        gear = 1,
        pedal_pos = 2
     };
}

namespace gearLever {
    enum gear {
        park = 0,
        rear = 1,
        neutral = 2,
        drive = 3
     };
}


