#include "Emulator.h"
#include <iostream>

#include "socketcan_cpp.h"
#include "socketcansetup.h"

#include <chrono> // std::chrono::microseconds
#include <thread>

using namespace std;

int main() {

  scpp::SocketCan socket_can;
  InitSocketcan(socket_can);
  scpp::CanFrame in_fr, out_fr;

  out_fr.len = 8;
  out_fr.id = ENGINE_FRAME_ID;

  Emulator volvo;

  while (true) {

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    ReadMessage(socket_can, in_fr);

    if (in_fr.id == USER_FRAME_ID) {
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

      out_fr.data[0] = volvo.getCarSpeed();
      out_fr.data[1] = volvo.getCurrentGear();
      out_fr.data[2] = volvo.getDGear();
      out_fr.data[3] = volvo.getEngineState();
      out_fr.data[4] = volvo.getCurrentRPM();

      cout << "out_fr[0] Speed: " << int(out_fr.data[0]) << endl;
      cout << "out_fr[1] gear: " << int(out_fr.data[1]) << endl;
      cout << "out_fr[2] Dgear: " << int(out_fr.data[2]) << endl;
      cout << "out_fr[3] EngState: " << int(out_fr.data[3]) << endl;
      cout << "out_fr[3] RPM: " << int(out_fr.data[4]) << endl;

      SendMessage(socket_can, out_fr);
    }
  }
  return 0;
}