#include "Emulator.h"
#include <iostream>
#include <sstream>

#include "socketcan_cpp.h"
#include "socketcansetup.h"

#include <chrono> // std::chrono::microseconds
#include <thread>

#include <bitset>

using namespace std;

int main() {

  scpp::SocketCan socket_can;
  InitSocketcan(socket_can);
  scpp::CanFrame in_fr, out_fr;

  out_fr.len = 8;
  out_fr.id = ENGINE_FRAME_ID;

  unsigned int rpm = 650;
  std::bitset<8> hex_rpm;

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

      rpm = volvo.getCurrentRPM();
      hex_rpm = rpm;
      // uint8 in; /* input in */ uint8 out1 = in & 0xf, out2 = in >> 4u;
      // out_fr.data[4] = rpm & 0xf >> 0;
      // out_fr.data[5] = rpm & 0xf0 >> 4;
      // out_fr.data[6] = rpm & 0xf00 >> 8;
      // out_fr.data[7] = rpm & 0xf000 >> 12;

      out_fr.data[4] = ((rpm & 0xf000) >> 12);
      out_fr.data[5] = ((rpm & 0xf00) >> 8);
      out_fr.data[6] = ((rpm & 0xf0) >> 4);
      out_fr.data[7] = ((rpm & 0xf) >> 0);

      cout << ((rpm & 0xf000) >> 12) << endl;
      cout << ((rpm & 0xf00) >> 8) << endl;
      cout << ((rpm & 0xf0) >> 4) << endl;
      cout << ((rpm & 0xf) >> 0) << endl;

      // // (a << 16) | (b << 8)
      cout << "out_fr[4-7] RPM: "
           << int((out_fr.data[4] << 12) | (out_fr.data[5]) << 8 |
                  (out_fr.data[6]) << 4 | (out_fr.data[7]) << 0)
           << endl;
      // // cout << "out_fr[4] RPM: " << int(out_fr.data[5]) << endl;

      SendMessage(socket_can, out_fr);
    }
  }
  return 0;
}