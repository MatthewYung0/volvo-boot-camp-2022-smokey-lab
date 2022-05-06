#include "Emulator.h"
#include <iostream>
//
#include "canmessage.h"
#include "checkinput.h"
#include "socketcan_cpp.h"
#include "socketcansetup.h"
#include <curses.h>

#include <chrono> // std::chrono::microseconds
#include <thread>

using namespace std;

int main() {

  scpp::SocketCan sockat_can;
  InitSocketcan(sockat_can);
  scpp::CanFrame fr;

  Emulator volvo;

  volvo.setEngineState(1);
  volvo.setCurrentGear(3);
  // volvo.setCurrentGear(0);
  volvo.setPedalD(1);
  // volvo.setPedalU(1);
  // volvo.shiftUp();
  // volvo.shiftUp();
  // volvo.shiftUp();
  // volvo.shiftUp();
  // volvo.shiftUp();

  int i = 1000;
  // int i = 7000;
  int dg = volvo.getDGear();

  while (true) {

    std::this_thread::sleep_for(300ms);
    // ReadMessage(sockat_can, fr);

    volvo.moveForward();
    // volvo.moveRearward();
    if (dg < volvo.getDGear()) {
      cout << "DGear In IF : " << volvo.getDGear() << endl;
      dg = volvo.getDGear();
      i = volvo.getCurrentRPM();
    }
    cout << "currenRPM: " << volvo.getCurrentRPM() << endl;
    cout << "carSpeed: " << volvo.getCarSpeed() << endl;
    cout << "DGear: " << volvo.getDGear() << endl;
    volvo.setCurrentRPM(i);
    i += 1000;
    // i -= 5000;
  }

  /*
   cout << int(fr.data[0]) << " " << int(fr.data[1]) << " " << int(fr.data[2])
        << " " << int(fr.data[3]) << " " << int(fr.data[4]) << " "
        << int(fr.data[5]) << " " << int(fr.data[6]) << " " << int(fr.data[7])
        << endl;
        */
}