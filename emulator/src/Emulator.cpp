#include "Emulator.h"

Emulator::Emulator() {
  idleRPM = 650;
  maxRPM = 5500;
  currentRPM = 0;
  carSpeed = 0;
  engineState = 0;

  currentGear = 2; // Set park as default
  dGear = 1;
  maxGear = 6;
  gearRatio[0] = -4.28; // * 0.02;
  gearRatio[1] = 3.81;  //  * 0.02;
  gearRatio[2] = 2.71;  //  * 0.02;
  gearRatio[3] = 1.37;  // * 0.02;
  gearRatio[4] = 1.0;   // * 0.02;
  gearRatio[5] = 0.81;  //  * 0.02;
  // gearRatio[] = {-4.28, 3.81, 2.71, 1.37, 1.0, 0.81};
};

Emulator::~Emulator(){};

int Emulator::getIdleRPM() { return idleRPM; }
int Emulator::getMaxRPM() { return maxRPM; }
int Emulator::getCurrentRPM() { return currentRPM; }
bool Emulator::getEngineState() { return engineState; }

void Emulator::setCurrentRPM(int currentRPM) { this->currentRPM = currentRPM; }
void Emulator::setEngineState(bool engineState) {
  this->engineState = engineState;
}

float Emulator::moveRearward() {
  // Check first if RPM is in the correct range
  if (currentRPM >= idleRPM && currentRPM <= maxRPM)
    carSpeed = currentRPM * gearRatio[0];

  std::cout << "Move R: " << currentRPM * gearRatio[0] << "  " << carSpeed
            << std::endl;
  std::cout << "currentRPM: " << currentRPM << " gearRatio: " << gearRatio[0]
            << std::endl;
  return carSpeed;
}

float Emulator::moveForward() {
  // Set limitation when to change gear
  // last one have no limitation
  int upperLimit = 1500;
  if (dGear == maxGear)
    upperLimit = 0;
  else
    upperLimit = 1500;

  // Check first if RPM is in the correct range
  if (currentRPM >= idleRPM && currentRPM < maxRPM) {
    // ShiftUp when RPM is 1500 rpm bellow the maxRPM
    // and above 2000 rpm for all gears except the last one
    if ((currentRPM > 2000) && (currentRPM == (maxRPM - upperLimit))) {
      shiftUp();
      // Set (decrease) RPM to 2000
      currentRPM = 2000;
      carSpeed = currentRPM * gearRatio[dGear];
    } else if (currentRPM <= (maxRPM - 1500)) {
      carSpeed = currentRPM * gearRatio[dGear];
      // If the RPM is bellow 1500 rpm, shiftDown
      // and set (increase) RPM to 2000
    } else if (currentRPM <= 1500) {
      shiftDown();
      currentRPM = 2000;
      carSpeed = currentRPM * gearRatio[dGear];
    }
  }

  std::cout << "Move F: " << currentRPM * gearRatio[dGear] << "  " << carSpeed
            << std::endl;
  std::cout << "currentRPM: " << currentRPM
            << " gearRatio: " << gearRatio[dGear] << " dGear: " << dGear
            << std::endl;
  return carSpeed;
}

//********************************************************
// GearBox

int Emulator::getMaxGear() { return maxGear; };

bool Emulator::checkGear(int gearInput) {
  // Check if user input is correct
  return gearInput > -1 && gearInput < 4;
}

int Emulator::getCurrentGear() { return currentGear; }

void Emulator::setCurrentGear(int gearInput) {
  if (checkGear(gearInput)) {
    this->currentGear = gearInput;
  }
}

void Emulator::setDGear() { dGear = 1; };

int Emulator::getDGear() { return dGear; };

float Emulator::getCarSpeed() { return carSpeed; };

void Emulator::setCarSpeed(float carSpeed) { this->carSpeed = carSpeed; };

void Emulator::shiftUp() {
  // Check if D gear is inside interval 1-5
  if (dGear > 0 && dGear < maxGear)
    dGear++;
}

void Emulator::shiftDown() {
  // Check if D gear is inside interval 1-5
  if (dGear > 1 && dGear < maxGear + 1)
    dGear--;
}