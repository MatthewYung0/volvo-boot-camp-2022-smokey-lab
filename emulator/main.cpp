#include "Emulator.h"
#include <iostream>

using namespace std;

int main() {
  Emulator volvo;
  cout << "currenRPM: " << volvo.getCurrentRPM() << endl;
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  volvo.setCurrentRPM(700);
  cout << "currentRPM: " << volvo.getCurrentRPM() << endl << endl;

  cout << "idleRPM: " << volvo.getIdleRPM() << endl;
  cout << "maxRPM: " << volvo.getMaxRPM() << endl << endl;

  cout << "MaxGear: " << volvo.getMaxGear() << endl;
  cout << "currentGear default: " << volvo.getCurrentGear() << endl;
  volvo.setCurrentGear(0);
  cout << "currentGear 0: " << volvo.getCurrentGear() << endl << endl;
  volvo.moveRearward();
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;

  cout << "DGear: " << volvo.getDGear() << endl;
  volvo.shiftUp();
  volvo.shiftUp();
  cout << "DGear, ShiftUp 2: " << volvo.getDGear() << endl;
  volvo.shiftDown();
  cout << "DGear, ShiftDown 1: " << volvo.getDGear() << endl;
  volvo.shiftUp();
  volvo.shiftUp();
  volvo.shiftUp();
  volvo.setCurrentRPM(4500);
  volvo.moveForward();
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
}