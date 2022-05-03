#include <iostream>
#include "can_message.h"

#define IGNITION 0
#define GEAR 1
#define PEDAL_POS 2

enum UserInput {
    start_stop = 115 , gear_drive = 100, gear_rear = 114,
    gear_neutral = 110, gear_park = 112, pedal_down = 259,
    pedal_up = 258, throttle_0 = 48, throttle_10 = 49, throttle_20 = 50, 
    throttle_30 = 51, throttle_40 = 52, throttle_50 = 53, throttle_60 = 54, 
    throttle_70 = 55, throttle_80 = 56, throttle_90 = 57,  
};

CanMessage::CanMessage() {
    this->frame.id = 0xEC;
    this->frame.len = 8;
    this->frame.flags = 0;
    for (int i = 0; i < 8; ++i) {
        this->frame.data[i] = 0;
    }
}

scpp::CanFrame CanMessage::GetFrame() {
    return this->frame;
}

void CanMessage::SetIgnition() {
    this->ignition_state = !(this->ignition_state);
    this->frame.data[IGNITION] = this->ignition_state;
}
void CanMessage::SetGearNeutral() {
    this->frame.data[GEAR] = 0;
}
void CanMessage::SetGearPark() {
    this->frame.data[GEAR] = 1;
}
void CanMessage::SetGearDrive() {
    this->frame.data[GEAR] = 8;
}
void CanMessage::SetGearRear() {
    this->frame.data[GEAR] = 2;
}
void CanMessage::SetPedalPosUp() {
    if (this->frame.data[PEDAL_POS] >= 10)
        this->frame.data[PEDAL_POS] -= 10;
}
void CanMessage::SetPedalPosDown() {
    if (this->frame.data[PEDAL_POS] <= 90)
        this->frame.data[PEDAL_POS] += 10;
}

void CanMessage::SetPedalPos(int _pedal_pos) {
    this->frame.data[PEDAL_POS] = _pedal_pos;
}

void CanMessage::SetFrame(int _input) {
    // Call different functions to set CAN message data from user input
    std::cout << _input << std::endl;
    switch (_input)
    {
    case UserInput::start_stop:
        std::cout << "start_stop" << std::endl;
        CanMessage::SetIgnition();
        break;
    case UserInput::gear_drive:
        std::cout << "gear_drive" << std::endl;
        CanMessage::SetGearDrive();
        break;
    case UserInput::gear_rear:
        std::cout << "gear_rear" << std::endl;
        CanMessage::SetGearRear();
        break;
    case UserInput::gear_neutral:
        std::cout << "gear_neutral" << std::endl;
        CanMessage::SetGearNeutral();
        break;
    case UserInput::gear_park:
        std::cout << "gear_park" << std::endl;
        CanMessage::SetGearPark();
        break;
    case UserInput::pedal_up:
        std::cout << "pedal_up" << std::endl;
        CanMessage::SetPedalPosUp();
        break;
    case UserInput::pedal_down:
        std::cout << "pedal_down" << std::endl;
        CanMessage::SetPedalPosDown();
        break;
    
    case UserInput::throttle_0:
        std::cout << "throttle_0" << std::endl;
        CanMessage::SetPedalPos(0);
        break;
    case UserInput::throttle_10:
        std::cout << "throttle_10" << std::endl;
        CanMessage::SetPedalPos(10);
        break;
    case UserInput::throttle_20:
        std::cout << "throttle_20" << std::endl;
        CanMessage::SetPedalPos(20);
        break;
    case UserInput::throttle_30:
        std::cout << "throttle_30" << std::endl;
        CanMessage::SetPedalPos(30);
        break;
    case UserInput::throttle_40:
        std::cout << "throttle_40" << std::endl;
        CanMessage::SetPedalPos(40);
        break;
    case UserInput::throttle_50:
        std::cout << "throttle_50" << std::endl;
        CanMessage::SetPedalPos(50);
        break;
    case UserInput::throttle_60:
        std::cout << "throttle_60" << std::endl;
        CanMessage::SetPedalPos(60);
        break;
    case UserInput::throttle_70:
        std::cout << "throttle_70" << std::endl;
        CanMessage::SetPedalPos(70);
        break;
    case UserInput::throttle_80:
        std::cout << "throttle_80" << std::endl;
        CanMessage::SetPedalPos(80);
        break;
    case UserInput::throttle_90:
        std::cout << "throttle_90" << std::endl;
        CanMessage::SetPedalPos(90);
        break;

    default:
        break;
    }
}