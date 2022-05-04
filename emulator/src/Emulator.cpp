#include "Emulator.h"

Emulator::Emulator()
    : gearRatio{-0.0085, 0.0077, 0.0123, 0.0185, 0.023, 0.81}, idleRPM(650),
      maxRPM(6500), maxGear(5) {

  currentRPM = 0;
  carSpeed = 0;
  engineState = 0;
  currentGear = 2; // Set park as default
  dGear = 1;
};

// Emulator() = default;
Emulator::~Emulator(){};

int Emulator::getIdleRPM() const { return idleRPM; }
int Emulator::getMaxRPM() const { return maxRPM; }
int Emulator::getCurrentRPM() const { return currentRPM; }
bool Emulator::getEngineState() const { return engineState; }

void Emulator::setCurrentRPM(int currentRPM) {
  // Check if RPM is inside the range
  if (currentRPM < idleRPM)
    currentRPM = idleRPM;
  else if (currentRPM > maxRPM)
    currentRPM = maxRPM;

  this->currentRPM = currentRPM;
}

void Emulator::setEngineState(bool engineState) {
  this->engineState = engineState;
}

void Emulator::moveRearward() {
  // Check first if RPM is in the correct range
  if (currentRPM >= idleRPM && currentRPM <= maxRPM) {
    carSpeed = abs(currentRPM * gearRatio[0]);
    std::cout << "4 " << std::endl;
  }

  setCarSpeed(carSpeed);
  // Test printout
  std::cout << "Move R: " << currentRPM * gearRatio[0] << "  " << carSpeed
            << std::endl;
  std::cout << "currentRPM: " << currentRPM << " gearRatio: " << gearRatio[0]
            << std::endl;
}

void Emulator::moveForward() {
  // Set limitation when to change gear
  // last one have no limitation
  int upperLimit = 1500;
  if (dGear == maxGear)
    upperLimit = 0;

  std::cout << ((this->currentRPM > currentRPM) ? "True" : "False")
            << std::endl;
  std::cout << this->currentRPM << std::endl;
  std::cout << currentRPM << std::endl;
  std::cout << getCurrentRPM() << std::endl;

  // Check first if RPM is in the correct range
  if (currentRPM >= idleRPM && currentRPM <= maxRPM) {
    std::cout << "\n000 " << std::endl;
    std::cout << "\n000 " << std::endl;
    // ShiftUp when RPM is 1500 rpm bellow the maxRPM
    // and above 2000 rpm for all gears except the last one
    if ((currentRPM > 2000) && (currentRPM == (maxRPM - upperLimit))) {
      shiftUp();
      // Set (decrease) RPM to 2000
      currentRPM = 2000;
      carSpeed = currentRPM * gearRatio[dGear];
      std::cout << "\n111 " << std::endl;
    } else if (currentRPM <= (maxRPM - 1500)) {
      carSpeed = currentRPM * gearRatio[dGear];
      std::cout << "\n222" << std::endl;
      // If the RPM is bellow 1500 rpm, shiftDown
      // and set (increase) RPM to 2000
    } else if (currentRPM <= 1500) {
      shiftDown();
      currentRPM = 2000;
      carSpeed = currentRPM * gearRatio[dGear];
      std::cout << "\333 " << std::endl;
    } else {
      carSpeed = currentRPM * gearRatio[dGear];
      std::cout << "\nDEF " << std::endl;
    }
  }

  setCarSpeed(carSpeed);

  // Test printout
  std::cout << "Move F: " << currentRPM * gearRatio[dGear] << "  " << carSpeed
            << std::endl;
  std::cout << "currentRPM: " << currentRPM
            << " gearRatio: " << gearRatio[dGear] << " dGear: " << dGear
            << std::endl;
  // return carSpeed;
}

//********************************************************
// GearBox

int Emulator::getMaxGear() const { return maxGear; };

bool Emulator::checkGear(int gearInput) {
  // Check if user input is correct
  return gearInput > -1 && gearInput < 4;
}

int Emulator::getCurrentGear() const { return currentGear; }

void Emulator::setCurrentGear(int gearInput) {
  if (checkGear(gearInput)) {
    this->currentGear = gearInput;
  }
}

void Emulator::setDGear() { dGear = 1; };

int Emulator::getDGear() const { return dGear; };

float Emulator::getCarSpeed() const { return carSpeed; };

void Emulator::setCarSpeed(float carSpeed) { this->carSpeed = carSpeed; };

void Emulator::shiftUp() {
  // Check if D gear is inside interval 1-5
  if (dGear > 0 && dGear <= maxGear)
    dGear++;
}

void Emulator::shiftDown() {
  // Check if D gear is inside interval 1-5
  if (dGear > 1 && dGear < maxGear + 1)
    dGear--;
}