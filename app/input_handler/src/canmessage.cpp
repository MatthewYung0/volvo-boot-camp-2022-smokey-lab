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
  this->frame.data[user_frame_data_partition::EXIT] = keyboard_common_input::EXIT;
}

void CanMessage::SetFrame(int _input) {
  std::cout << _input << "\n\r";
  switch (_input) {
  case keyboard_input::START_STOP:
    CanMessage::SetIgnition();
    break;
  case keyboard_input::GEAR_DRIVE:
    CanMessage::SetGearDrive();
    break;
  case keyboard_input::GEAR_REAR:
    CanMessage::SetGearRear();
    break;
  case keyboard_input::GEAR_NEUTRAL:
    CanMessage::SetGearNeutral();
    break;
  case keyboard_input::GEAR_PARK:
    CanMessage::SetGearPark();
    break;
  case keyboard_input::THROTTLE_0:
    CanMessage::SetPedalPos(0);
    break;
  case keyboard_input::THROTTLE_10:
    CanMessage::SetPedalPos(10);
    break;
  case keyboard_input::THROTTLE_20:
    CanMessage::SetPedalPos(20);
    break;
  case keyboard_input::THROTTLE_30:
    CanMessage::SetPedalPos(30);
    break;
  case keyboard_input::THROTTLE_40:
    CanMessage::SetPedalPos(40);
    break;
  case keyboard_input::THROTTLE_50:
    CanMessage::SetPedalPos(50);
    break;
  case keyboard_input::THROTTLE_60:
    CanMessage::SetPedalPos(60);
    break;
  case keyboard_input::THROTTLE_70:
    CanMessage::SetPedalPos(70);
    break;
  case keyboard_input::THROTTLE_80:
    CanMessage::SetPedalPos(80);
    break;
  case keyboard_input::THROTTLE_90:
    CanMessage::SetPedalPos(90);
    break;
  case keyboard_common_input::EXIT:
    CanMessage::InitiateGracefulShutdown();
    break;

  default:
    break;
  }
}