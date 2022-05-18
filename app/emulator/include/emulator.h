#pragma once

#include "common_datatypes.h"
#include <iostream>

class Emulator {
public:
  bool getEngineState() const;
  void setEngineState(int);
  float getCarSpeed() const;

  int getCurrentRPM() const;
  void setCurrentRPM(int);

  int getCurrentGear() const;
  void setCurrentGear(int);
  int getDGear() const; // Get current drive gear

  void moveRearward();
  void moveForward();

  void shiftUp();
  void shiftDown();

  Emulator();

private:
  const float gear_ratio[7]; // Define gear ration, position 0 is for Reverse
  const int idle_rpm;        // idle RPM
  const int max_rpm;         // max RPM
  const int max_gear;        // Number of gears in D-mode
  const int rpm_range;       // engine rpm interval
  int current_rpm;           // RPM from the pedal position
  int previous_pedal_input;  // Previous pedal state
  int car_speed;             // actual car speed
  bool engine_state;         // engine_state true/false
  int gear;                  /*
                               Input gear 0-3:
                                -> 0: gear for park
                                -> 1: gear for reverse
                                -> 2: gear for neutral
                                -> 3: gear for drive
                             */
  int dGear;                 // Drive mode gear 1-5
  int pedal;

  int getIdleRPM() const;
  int getMaxRPM() const;

  void setCarSpeed(float);

  //********************************************************
  // GearBox

  bool checkGear(int);
  void setDGear(); // Set initial current drive gear to 1
  int getMaxGear() const;
};