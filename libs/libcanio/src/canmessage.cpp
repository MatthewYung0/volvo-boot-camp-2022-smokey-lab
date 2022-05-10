#include "canmessage.h"
#include "check_input.h"
#include <iostream>

CanMessage::CanMessage() {
  this->frame.id = INPUT_HANDLER_FRAME_ID;
  this->frame.len = 8;
  this->frame.flags = 0;
  for (int i = 0; i < 8; i++) {
    this->frame.data[i] = 0;
  }
}

void CanMessage::SetIgnition() {
  this->ignition_state = !(this->ignition_state);
  this->frame.data[canData::DataElement::ignition] = this->ignition_state;
}
void CanMessage::SetGearPark() {
  this->frame.data[gearLever::gear::park] = GEAR_PARK;
}
void CanMessage::SetGearRear() {
  this->frame.data[gearLever::gear::rear] = GEAR_REAR;
}
void CanMessage::SetGearNeutral() {
  this->frame.data[gearLever::gear::neutral] = GEAR_NEUTRAL;
}
void CanMessage::SetGearDrive() {
  this->frame.data[gearLever::gear::drive] = GEAR_DRIVE;
}
void CanMessage::SetPedalPos(int _pedal_pos) {
  this->frame.data[canData::DataElement::pedal_pos] = _pedal_pos;
}

void CanMessage::SetFrame(int _input) {
  std::cout << _input << std::endl;
  switch (_input) {
  case START_STOP:
    CanMessage::SetIgnition();
    break;
  case GEAR_DRIVE:
    CanMessage::SetGearDrive();
    break;
  case GEAR_REAR:
    CanMessage::SetGearRear();
    break;
  case GEAR_NEUTRAL:
    CanMessage::SetGearNeutral();
    break;
  case GEAR_PARK:
    CanMessage::SetGearPark();
    break;
  case THROTTLE_0:
    CanMessage::SetPedalPos(0);
    break;
  case THROTTLE_10:
    CanMessage::SetPedalPos(10);
    break;
  case THROTTLE_20:
    CanMessage::SetPedalPos(20);
    break;
  case THROTTLE_30:
    CanMessage::SetPedalPos(30);
    break;
  case THROTTLE_40:
    CanMessage::SetPedalPos(40);
    break;
  case THROTTLE_50:
    CanMessage::SetPedalPos(50);
    break;
  case THROTTLE_60:
    CanMessage::SetPedalPos(60);
    break;
  case THROTTLE_70:
    CanMessage::SetPedalPos(70);
    break;
  case THROTTLE_80:
    CanMessage::SetPedalPos(80);
    break;
  case THROTTLE_90:
    CanMessage::SetPedalPos(90);
    break;

  default:
    break;
  }
}