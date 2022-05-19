#include "canmessage.h"
#include "common_datatypes.h"
#include <iostream>

CanMessage::CanMessage() {
  this->frame.id = USER_FRAME_ID;
  this->frame.len = 8;
  this->frame.flags = 0;
  for (int i = 0; i < 8; i++) {
    this->frame.data[i] = 0;
  }
}

void CanMessage::SetIgnition() {
  this->ignition_state = !(this->ignition_state);
  this->frame.data[user_frame_data_partition::IGNITION] = this->ignition_state;
}
void CanMessage::SetGearPark() {
  this->frame.data[user_frame_data_partition::LEVER] = gear_lever::PARK;
}
void CanMessage::SetGearRear() {
  this->frame.data[user_frame_data_partition::LEVER] = gear_lever::REAR;
}
void CanMessage::SetGearNeutral() {
  this->frame.data[user_frame_data_partition::LEVER] = gear_lever::NEUTRAL;
}
void CanMessage::SetGearDrive() {
  this->frame.data[user_frame_data_partition::LEVER] = gear_lever::DRIVE;
}
void CanMessage::SetPedalPos(int _pedal_pos) {
  this->frame.data[user_frame_data_partition::PEDAL_POS] = _pedal_pos;
}
void CanMessage::InitiateGracefulShutdown() {
  this->frame.data[user_frame_data_partition::EXIT] =
      keyboard_common_input::EXIT;
}

void CanMessage::SetFrame(int _input) {
  // std::cout << _input << "\n\r";
  switch (_input) {
  case keyboard_input::START_STOP:
    std::cout << "Key pressed: " << _input << " | "
              << "START / STOP"
              << "\n\r";
    CanMessage::SetIgnition();
    break;
  case keyboard_input::GEAR_DRIVE:
    std::cout << "Key pressed: " << _input << " | "
              << "GEAR DRIVE"
              << "\n\r";
    CanMessage::SetGearDrive();
    break;
  case keyboard_input::GEAR_REAR:
    std::cout << "Key pressed: " << _input << " | "
              << "GEAR REVERSE"
              << "\n\r";
    CanMessage::SetGearRear();
    break;
  case keyboard_input::GEAR_NEUTRAL:
    std::cout << "Key pressed: " << _input << " | "
              << "GEAR NEUTRAL"
              << "\n\r";
    CanMessage::SetGearNeutral();
    break;
  case keyboard_input::GEAR_PARK:
    std::cout << "Key pressed: " << _input << " | "
              << "GEAR PARK"
              << "\n\r";
    CanMessage::SetGearPark();
    break;
  case keyboard_input::THROTTLE_0:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 0%"
              << "\n\r";
    CanMessage::SetPedalPos(0);
    break;
  case keyboard_input::THROTTLE_10:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 10%"
              << "\n\r";
    CanMessage::SetPedalPos(10);
    break;
  case keyboard_input::THROTTLE_20:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 20%"
              << "\n\r";
    CanMessage::SetPedalPos(20);
    break;
  case keyboard_input::THROTTLE_30:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 30%"
              << "\n\r";
    CanMessage::SetPedalPos(30);
    break;
  case keyboard_input::THROTTLE_40:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 40%"
              << "\n\r";
    CanMessage::SetPedalPos(40);
    break;
  case keyboard_input::THROTTLE_50:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 50%"
              << "\n\r";
    CanMessage::SetPedalPos(50);
    break;
  case keyboard_input::THROTTLE_60:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 60%"
              << "\n\r";
    CanMessage::SetPedalPos(60);
    break;
  case keyboard_input::THROTTLE_70:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 70%"
              << "\n\r";
    CanMessage::SetPedalPos(70);
    break;
  case keyboard_input::THROTTLE_80:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 80%"
              << "\n\r";
    CanMessage::SetPedalPos(80);
    break;
  case keyboard_input::THROTTLE_90:
    std::cout << "Key pressed: " << _input << "  | "
              << "THROTTLE: 90%"
              << "\n\r";
    CanMessage::SetPedalPos(90);
    break;
  case keyboard_common_input::EXIT:
    std::cout << "Key pressed: " << _input << "  | "
              << "EXIT APPLICATION"
              << "\n\r";
    CanMessage::InitiateGracefulShutdown();
    break;

  default:
    break;
  }
}
