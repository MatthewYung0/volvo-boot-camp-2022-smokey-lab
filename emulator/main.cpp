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
  volvo.setCurrentRPM(6000);
  cout << "currentGear to 0 (Reverse): " << volvo.getCurrentGear() << endl
       << endl;
  volvo.moveRearward();
  cout << "currentRPM after R: " << volvo.getCurrentRPM() << endl;
  cout << "carSpeed R: " << volvo.getCarSpeed() << endl << endl;

  cout << "DGear: " << volvo.getDGear() << endl;
  volvo.shiftUp();
  volvo.shiftUp();
  cout << "DGear, ShiftUp 2: " << volvo.getDGear() << endl;
  volvo.shiftDown();
  cout << "DGear, ShiftDown 1: " << volvo.getDGear() << endl << endl;
  volvo.shiftUp();
  volvo.shiftUp();
  volvo.shiftUp();
  volvo.setCurrentRPM(6499);
  volvo.moveForward();
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  volvo.shiftDown();
  volvo.moveForward();
  cout << "\nDGear, ShiftDown 1: " << volvo.getDGear() << endl << endl;
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  volvo.shiftDown();
  volvo.moveForward();
  cout << "\nDGear, ShiftDown 1: " << volvo.getDGear() << endl << endl;
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  volvo.shiftDown();
  volvo.moveForward();
  cout << "\nDGear, ShiftDown 1: " << volvo.getDGear() << endl << endl;
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  volvo.shiftDown();
  volvo.moveForward();
  cout << "\nDGear, ShiftDown 1: " << volvo.getDGear() << endl << endl;
  cout << "carSpeed: " << volvo.getCarSpeed() << endl;
  cout << "#################################" << endl;
  volvo.setCurrentRPM(6000);
  volvo.moveForward();
  cout << "#################################" << endl;
  volvo.setCurrentRPM(2000);
  volvo.moveForward();
  cout << "#################################" << endl;
  volvo.setCurrentRPM(4000);
  volvo.moveForward();
  cout << "#################################" << endl;
  volvo.setCurrentRPM(6000);
  volvo.moveForward();
}