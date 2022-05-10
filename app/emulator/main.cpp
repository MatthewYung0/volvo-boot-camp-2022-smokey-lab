
#include "Emulator.h"
#include <iostream>
//
#include "canmessage.h"
#include "socketcan_cpp.h"
#include "socketcansetup.h"

#include <curses.h>

#include <chrono> // std::chrono::microseconds
#include <thread>

using namespace std;

int main() {

  scpp::SocketCan sockat_can;
  InitSocketcan(sockat_can);
  scpp::CanFrame in_fr;

  // int ch = 0;
  // CanMessage can_msg;

  Emulator volvo;

  while (true) {

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ReadMessage(sockat_can, in_fr);

    if (in_fr.id == 0xAAA) {
      volvo.setEngineState(in_fr.data[0]);
      volvo.setCurrentGear(in_fr.data[1]);

      if (in_fr.data[1] == 3) {
        volvo.moveForward();
        cout << "Move Forward" << endl;
      } else if (in_fr.data[1] == 1) {
        volvo.moveRearward();
        cout << "Move Rearward" << endl;
      }

      volvo.setCurrentRPM(int(in_fr.data[2]));
      cout << "Pedal value: " << int(in_fr.data[2]) << endl;
      cout << "--------------------------" << endl;
      cout << "currenRPM: " << volvo.getCurrentRPM() << endl;
      cout << "carSpeed: " << volvo.getCarSpeed() << endl;
      cout << "DGear: " << volvo.getDGear() << endl;
      cout << "InputGear: " << volvo.getCurrentGear() << endl;
      cout << "--------------------------" << endl;
      //   if ((ch = getch()) == ERR) {
      //   }
      //   can_msg.SetFrame(ch);
      //   SendMessage(sockat_can, can_msg.frame);
      // }
    }
  }
  return 0;
}