#pragma once

#include <iostream>

class Emulator {
public:
  int idleRPM;
  int maxRPM;
  int currentRPM;
  float carSpeed;
  bool engineState; // engineState as to whether it is on (1) or off (0)

  int currentGear; // Input gear 0-3
  // 0 gear for reverse
  // 1 gear for neutral
  // 2 gear for park
  // 3 gear for drive
  int dGear; // Drive mode gear 1-5
  int maxGear;
  float gearRatio[6]; // 0 position is reverse

  Emulator();
  Emulator(int, int, int, float, bool, int, int, int, float);
  ~Emulator();

  int getIdleRPM();
  int getMaxRPM();
  int getCurrentRPM();
  bool getEngineState();

  void setCurrentRPM(int);
  void setEngineState(bool);

  float moveRearward();
  float moveForward();

  float getCarSpeed();
  void setCarSpeed(float);

  //********************************************************
  // GearBox

  bool checkGear(int gearInput);
  int getCurrentGear();
  void setCurrentGear(int gearInput);
  int getDGear();  // Get current drive gear
  void setDGear(); // Set initial current drive gear to 1

  void shiftUp();
  void shiftDown();

  int getMaxGear();
};