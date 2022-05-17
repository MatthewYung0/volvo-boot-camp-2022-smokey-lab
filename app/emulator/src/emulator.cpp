#include "emulator.h"
#include <ctime>

Emulator::Emulator()
    : gear_ratio{-0.0085, 0.0097, 0.0155, 0.025, 0.027, 0.031, 0.034},
      idle_rpm(650), max_rpm(8500), max_gear(6), rpm_range(max_rpm - idle_rpm) {

  current_rpm = 0;
  previous_pedal_input = 0;
  car_speed = 0;
  engine_state_input = 0;
  engine_state = 0;
  gear = gear_lever::PARK; // Set gear_lever::PARK as default
  dGear = 1;
  pedal = 0;
  pedal_input = 0;
}

// Emulator() = default;
Emulator::~Emulator() {}

int Emulator::getIdleRPM() const { return idle_rpm; }
int Emulator::getMaxRPM() const { return max_rpm; }
int Emulator::getCurrentRPM() const { return current_rpm; }
bool Emulator::getEngineState() const { return engine_state; }

void Emulator::setCurrentRPM(int pedal_input) {

  // Check if accelerate or deaccelerate
  if (pedal_input > previous_pedal_input)
    pedal = 1;
  else if (pedal_input < previous_pedal_input)
    pedal = 0;

  float damp_fact = 100;
  if (dGear > 1 && (pedal_input * rpm_range / 100) > current_rpm && pedal) {
    damp_fact = 100 * float(current_rpm) / ((pedal_input * rpm_range) / 80);
  } else if ((pedal_input * rpm_range / 100) < current_rpm && !pedal) {
    damp_fact = 1000 * float(((pedal_input + 0.1 * dGear) * rpm_range) / 100) /
                current_rpm;
  }

  // Check if engine is on and R, N or D gear
  if (engine_state && !(gear == gear_lever::PARK)) {
    // Check if RPM is inside the range
    if (current_rpm < idle_rpm)
      this->current_rpm = idle_rpm + random() % 50;
    else if (current_rpm > max_rpm)
      this->current_rpm = max_rpm;
    else {
      if (pedal_input == 0 && car_speed <= 6)
        this->current_rpm = idle_rpm + random() % 50;
      else {
        if (damp_fact < pedal_input && pedal) {
          this->current_rpm = (previous_pedal_input + 1) * rpm_range / 100;
          previous_pedal_input += 1;
        } else if (damp_fact > pedal_input && !pedal) {
          this->current_rpm = (previous_pedal_input - 1) * rpm_range / 100;
          previous_pedal_input -= 1;
        } else {
          this->current_rpm = pedal_input * rpm_range / 100;
          previous_pedal_input = pedal_input;
        }
      }
    }

    // Store
    // previous_pedal_input = pedal_input;

  } else if (!engine_state) {
    // If engine is off, RPM = 0
    this->current_rpm = 0;
  }
}

void Emulator::setEngineState(int engine_state_input) {
  // Change engine state (on/off) only when car_speed is 0
  if (car_speed <= 6 && engine_state_input && gear == gear_lever::PARK) {
    this->engine_state = true;
    current_rpm = idle_rpm + random() % 50;
  } else if (car_speed <= 6 && !engine_state_input &&
             gear == gear_lever::PARK) {
    this->engine_state = false;
    // If engine is off
    current_rpm = 0;
    car_speed = 0;
  }
}

void Emulator::moveRearward() {
  // Check if speed is 0, engine is on and reverse gear
  if (engine_state && gear == gear_lever::REAR) {
    car_speed = abs(current_rpm * gear_ratio[0]);
  }
}

void Emulator::moveForward() {
  // Set limitation when to change gear
  // last one have no limitation
  int shift_u_limit = 0, shift_d_limit = 0;

  if (dGear == max_gear) {
    shift_u_limit = 0;
    shift_d_limit = 6000;
  } else {
    shift_u_limit = 4500;
    shift_d_limit = 5500;
  }

  // Check if, engine is on and D gear
  if (engine_state && gear == gear_lever::DRIVE) {
    if (pedal) {
      if (current_rpm > (max_rpm - shift_u_limit) && (dGear < max_gear)) {
        car_speed = current_rpm * gear_ratio[dGear];
        shiftUp();
        // Set the RPM after the shift to one corresponding to
        // actual speed and the gear ratio for the shifted gear
        current_rpm = car_speed / gear_ratio[dGear];
      } else {
        // Last gear, allow up to max_rpm
        car_speed = current_rpm * gear_ratio[dGear];
      }
    } else if (!pedal) {
      if (current_rpm < (max_rpm - shift_d_limit) && dGear > 1) {
        car_speed = current_rpm * gear_ratio[dGear];
        shiftDown();
        // Set the RPM after the shift to one corresponding to
        // actual speed and the gear ratio for the shifted gear
        current_rpm = car_speed / gear_ratio[dGear];
      } else {
        car_speed = current_rpm * gear_ratio[dGear];
      }
    }
  }
}

//********************************************************
// GearBox

int Emulator::getMaxGear() const { return max_gear; }

bool Emulator::checkGear(int gear) {
  // Check if user input is correct
  return gear > -1 && gear < 4;
}

int Emulator::getCurrentGear() const { return gear; }

// Set User input Gear, R, N, P or D and check if car_speed is 0
void Emulator::setCurrentGear(int gearIn) {
  if (checkGear(gear) && (car_speed <= 6)) {
    dGear = 1;
    this->gear = gearIn;
  }
}

// Set D mode gear
void Emulator::setDGear() { dGear = 1; }

int Emulator::getDGear() const { return dGear; }

float Emulator::getCarSpeed() const { return car_speed; }

void Emulator::setCarSpeed(float car_speed) {
  // limit car speed to interval 0-250
  if (car_speed < 0)
    car_speed = 0;
  else if (car_speed > 250)
    car_speed = 250;

  if (engine_state)
    this->car_speed = car_speed;
}

void Emulator::shiftUp() {
  // Check if D gear is inside interval 1-6
  if (dGear > 0 && dGear <= max_gear)
    dGear++;
}

void Emulator::shiftDown() {
  // Check if D gear is inside interval 1-6
  if (dGear > 1 && dGear < max_gear + 1)
    dGear--;
}