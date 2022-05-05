#include "Emulator.h"

Emulator::Emulator()
    : gearRatio{-0.0085, 0.00667, 0.0133, 0.02, 0.027, 0.029, 0.033},
      idleRPM(650), maxRPM(7500), maxGear(6) {

  currentRPM = 0;
  carSpeed = 0;
  engineState = 0;
  currentGear = 2; // Set park as default
  dGear = 1;
  pedalDown = 0;
  pedalUp = 0;
};

// Emulator() = default;
Emulator::~Emulator(){};

int Emulator::getIdleRPM() const { return idleRPM; }
int Emulator::getMaxRPM() const { return maxRPM; }
int Emulator::getCurrentRPM() const { return currentRPM; }
bool Emulator::getEngineState() const { return engineState; }

void Emulator::setPedalD(bool pedalDown) { this->pedalDown = pedalDown; }

void Emulator::setPedalU(bool pedalUp) { this->pedalUp = pedalUp; }

void Emulator::setCurrentRPM(int currentRPM) {
  // Check if engine is on and R, N or D gear
  if (engineState &&
      (currentGear == 0 || currentGear == 1 || currentGear == 3)) {
    // Check if RPM is inside the range
    if (currentRPM < idleRPM)
      currentRPM = idleRPM;
    else if (currentRPM > maxRPM)
      currentRPM = maxRPM;

    this->currentRPM = currentRPM;
  }
}

void Emulator::setEngineState(bool engineState) {
  // Change engine state (on/off) only when carSpeed is 0
  if (carSpeed == 0)
    this->engineState = engineState;
  // Set P mode
  setCurrentGear(2);
  // idle, even when off (default min)
  setCurrentRPM(idleRPM);
}

void Emulator::moveRearward() {
  // Check if speed is 0, engine is on and reverse gear
  if (carSpeed == 0 && engineState && currentGear == 0) {
    carSpeed = abs(currentRPM * gearRatio[0]);
    // std::cout << "4 " << std::endl;
  }

  // // Test printout
  // std::cout << "Move R: " << currentRPM * gearRatio[0] << "  " << carSpeed
  //           << std::endl;
  // std::cout << "currentRPM: " << currentRPM << " gearRatio: " << gearRatio[0]
  //           << std::endl;
}

void Emulator::moveForward() {
  // Set limitation when to change gear
  // last one have no limitation
  int upperLimit = 1500;
  if (dGear == maxGear)
    upperLimit = 0;

  // std::cout << ((this->currentRPM > currentRPM) ? "True" : "False")
  //           << std::endl;
  // std::cout << this->currentRPM << std::endl;
  // std::cout << currentRPM << std::endl;
  // std::cout << getCurrentRPM() << std::endl;
  // std::cout << "\nTEST " << std::endl;

  // Check if, engine is on and D gear
  if (engineState && currentGear == 3) {
    // std::cout << "\n000 " << std::endl;
    if (pedalDown) {
      // std::cout << "\nPedalD " << std::endl;
      // ShiftUp when above maxRPM - upperLimit rpm for all gears except the
      // last one
      if (currentRPM > (maxRPM - upperLimit) && (dGear < maxGear)) {
        shiftUp();
        // Set (decrease) RPM to 2000 * factor
        currentRPM = 2000 * (1 + dGear * dGear / 10);
        carSpeed = currentRPM * gearRatio[dGear];
        // std::cout << "\n1 " << std::endl;
      } else {
        shiftUp();
        // Set (decrease) RPM to 2000
        currentRPM = 2000;
        carSpeed = currentRPM * gearRatio[dGear];
        // std::cout << "\n2 " << std::endl;
      }
    } else if (pedalUp) {
      // ShiftDown when RPM is bellow 1500 rpm
      if ((currentRPM < 1500) && dGear > 1) {
        shiftDown();
        // Set (increase) RPM to 3000
        currentRPM = 3000;
        carSpeed = currentRPM * gearRatio[dGear];
        // std::cout << "\n3 " << std::endl;
      }
    }
  }

  // Test printout
  // std::cout << "Move F: " << currentRPM * gearRatio[dGear] << "  " <<
  // carSpeed
  //           << std::endl;
  // std::cout << "currentRPM: " << currentRPM
  //           << " gearRatio: " << gearRatio[dGear] << " dGear: " << dGear
  //           << std::endl;
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

// Set User input Gear, R, N, P or D
void Emulator::setCurrentGear(int gearInput) {
  if (checkGear(gearInput)) {
    this->currentGear = gearInput;
  }
}

// Set D mode gear
void Emulator::setDGear() { dGear = 1; };

int Emulator::getDGear() const { return dGear; };

float Emulator::getCarSpeed() const { return carSpeed; };

void Emulator::setCarSpeed(float carSpeed) { this->carSpeed = carSpeed; };

void Emulator::shiftUp() {
  // Check if D gear is inside interval 1-6
  if (dGear > 0 && dGear <= maxGear)
    dGear++;
}

void Emulator::shiftDown() {
  // Check if D gear is inside interval 1-6
  if (dGear > 1 && dGear < maxGear + 1)
    dGear--;
}