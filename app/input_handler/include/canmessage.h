#pragma once
#include "socketcan_cpp.h"

namespace keyboard_input {
static const int START_STOP = 's';
static const int GEAR_DRIVE = 'd';
static const int GEAR_REAR = 'r';
static const int GEAR_NEUTRAL = 'n';
static const int GEAR_PARK = 'p';
static const int THROTTLE_0 = 48;
static const int THROTTLE_10 = 49;
static const int THROTTLE_20 = 50;
static const int THROTTLE_30 = 51;
static const int THROTTLE_40 = 52;
static const int THROTTLE_50 = 53;
static const int THROTTLE_60 = 54;
static const int THROTTLE_70 = 55;
static const int THROTTLE_80 = 56;
static const int THROTTLE_90 = 57;

} // namespace keyboard_input

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
  void InitiateGracefulShutdown();
};