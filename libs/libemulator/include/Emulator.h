#pragma once

#include <iostream>

class Emulator {
public:
  const int idleRPM;        // idle RPM
  const int maxRPM;         // max RPM
  int currentRPM;           // RPM from the pedal position
  int carSpeed;             // actual car speed
  int engineStateInput;     // engineState user input
  bool engineState;         // engineState true/false
  int gearInput;            /*
                              Input gear 0-3:
                               -> 0: gear for reverse
                               -> 1: gear for neutral
                               -> 2: gear for park
                               -> 3: gear for drive
                              */
  int dGear;                // Drive mode gear 1-5
  const int maxGear;        // Number of gears in D-mode
  const float gearRatio[7]; // Define gear ration, position 0 is for Reverse
  int pedal;
  bool pedalDown; // Input, pedal position for increasing RPM
  bool pedalUp;   // Input, pedal position for decreasing RPM

  Emulator();
  // Emulator(int, int, int, float, bool, int, int, int, float, float);
  ~Emulator();

  int getIdleRPM() const;
  int getMaxRPM() const;
  int getCurrentRPM() const;
  bool getEngineState() const;

  void setCurrentRPM(int);
  void setEngineState(int);

  void moveRearward();
  void moveForward();

  float getCarSpeed() const;
  void setCarSpeed(float);

  void setPedalU(bool);
  // bool getPedalU() const;
  void setPedalD(bool);
  // bool getPedalD() const;

  //********************************************************
  // GearBox

  bool checkGear(int gearInput);
  int getCurrentGear() const;
  void setCurrentGear(int gearInput);
  int getDGear() const; // Get current drive gear
  void setDGear();      // Set initial current drive gear to 1

  void shiftUp();
  void shiftDown();

  int getMaxGear() const;
};