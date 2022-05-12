#include "Emulator.h"

Emulator::Emulator()
    : gearRatio{-0.0085, 0.00667, 0.0133, 0.02, 0.027, 0.029, 0.033},
      idleRPM(650), maxRPM(7500), maxGear(6), rpmRange(maxRPM - idleRPM) {

  currentRPM = 0;
  previousPedalInput = 0;
  carSpeed = 0;
  engineStateInput = 0;
  engineState = 0;
  gear = gear_lever::PARK; // Set gear_lever::PARK as default
  dGear = 1;
  pedal = 0;
  pedalInput = 0;
}

// Emulator() = default;
Emulator::~Emulator() {}

int Emulator::getIdleRPM() const { return idleRPM; }
int Emulator::getMaxRPM() const { return maxRPM; }
int Emulator::getCurrentRPM() const { return currentRPM; }
bool Emulator::getEngineState() const { return engineState; }

void Emulator::setCurrentRPM(int pedalInput) {
  // Check if accelerate or deaccelerate
  if (pedalInput > previousPedalInput)
    pedal = 1;
  else if (pedalInput < previousPedalInput)
    pedal = 0;

  float dampFact = 100;
  if (dGear > 1 && (pedalInput * rpmRange / 100) > currentRPM) {
    dampFact = 100 * float(currentRPM) / ((pedalInput * rpmRange) / 100);
  }

  std::cout << (pedal ? "PedalDown" : "PedalUp") << std::endl;

  // Check if engine is on and R, N or D gear
  if (engineState && !(gear == gear_lever::PARK)) {
    // Check if RPM is inside the range
    if (currentRPM < idleRPM)
      this->currentRPM = idleRPM;
    else if (currentRPM > maxRPM)
      this->currentRPM = maxRPM;
    else {
      if (pedalInput == 0)
        this->currentRPM = idleRPM;
      else {
        if (dampFact < pedalInput && pedal)
          this->currentRPM = dampFact * rpmRange / 100;
        // else if (dampFact < pedalInput && !pedal)
        //   this->currentRPM = dampFact * rpmRange / 100;
        else
          this->currentRPM = pedalInput * rpmRange / 100;
      }
    }

    // Store
    previousPedalInput = pedalInput;

  } else if (!engineState) {
    // If engine is off, RPM = 0
    this->currentRPM = 0;
    std::cout << "RPM = 0" << std::endl;
  }
}

void Emulator::setEngineState(int engineStateInput) {
  // Change engine state (on/off) only when carSpeed is 0
  if (carSpeed <= 5 && engineStateInput == 1 && gear == gear_lever::PARK) {
    this->engineState = true;
    if (currentRPM < idleRPM) {
      // Set idle RPM if engine is started
      currentRPM = idleRPM;
    }
  } else if (carSpeed <= 5 && engineStateInput == 0 &&
             gear == gear_lever::PARK) {
    this->engineState = false;
    // If engine is off
    currentRPM = 0;
  }
}

void Emulator::moveRearward() {
  // Check if speed is 0, engine is on and reverse gear
  // if (carSpeed == 0 && engineState && gear == 0) {
  if (engineState && gear == gear_lever::REAR) {
    carSpeed = abs(currentRPM * gearRatio[0]);
  }
}

void Emulator::moveForward() {
  // Set limitation when to change gear
  // last one have no limitation
  int upperLimit = 1500;
  if (dGear == maxGear)
    upperLimit = 0;

  // Check if, engine is on and D gear
  if (engineState && gear == gear_lever::DRIVE) {
    if (pedal) {
      // ShiftUp when above maxRPM - upperLimit rpm for all gears except the
      // last one
      if (currentRPM > (maxRPM - upperLimit) && (dGear < maxGear)) {
        carSpeed = currentRPM * gearRatio[dGear];
        shiftUp();
        // Set the RPM after the shift to one corresponding to
        // actual speed and the gear ratio for the shifted gear
        currentRPM = carSpeed / gearRatio[dGear];

      } else {
        // Last gear, allow up to maxRPM
        carSpeed = currentRPM * gearRatio[dGear];
      }
    } else if (!pedal) {
      // ShiftDown when RPM is bellow 1500 rpm
      if ((currentRPM < 1500) && dGear > 1) {
        carSpeed = currentRPM * gearRatio[dGear];
        shiftDown();
        // Set the RPM after the shift to one corresponding to
        // actual speed and the gear ratio for the shifted gear
        currentRPM = carSpeed / gearRatio[dGear];
      } else {
        carSpeed = currentRPM * gearRatio[dGear];
      }
    }
  }
}

//********************************************************
// GearBox

int Emulator::getMaxGear() const { return maxGear; }

bool Emulator::checkGear(int gear) {
  // Check if user input is correct
  return gear > -1 && gear < 4;
}

int Emulator::getCurrentGear() const { return gear; }

// Set User input Gear, R, N, P or D and check if carSpeed is 0
void Emulator::setCurrentGear(int gearIn) {
  if (checkGear(gear) && (carSpeed <= 5)) {
    /* if ((gear == gear_lever::DRIVE || gear == REVERSE) &&
        (gearIn != gear_lever::NEUTRAL || gearIn != gear_lever::PARK))
      this->gear = gearIn;
    else if ((gear == gear_lever::NEUTRAL || gear == gear_lever::PARK) &&
             (gearIn != gear_lever::DRIVE || gearIn != REVERSE))
      this->gear = gearIn; */

    dGear = 1;
    this->gear = gearIn;
  }
}

// Set D mode gear
void Emulator::setDGear() { dGear = 1; }

int Emulator::getDGear() const { return dGear; }

float Emulator::getCarSpeed() const { return carSpeed; }

void Emulator::setCarSpeed(float carSpeed) {
  // limit car speed to interval 0-250
  if (carSpeed < 0)
    carSpeed = 0;
  else if (carSpeed > 250)
    carSpeed = 250;

  // Chabge speed only when moving (gear R or D)
  if (gear == gear_lever::DRIVE || gear == gear_lever::REAR)
    this->carSpeed = carSpeed;
}

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