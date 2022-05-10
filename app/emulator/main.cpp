#include "Emulator.h"
#include <iostream>
//
#include "canmessage.h"
#include "socketcan_cpp.h"
#include "socketcansetup.h"

#include <chrono> // std::chrono::microseconds
#include <thread>

using namespace std;

int main()
{

  scpp::SocketCan sockat_can;
  InitSocketcan(sockat_can);
  scpp::CanFrame fr;

  int temp;

  Emulator volvo;

  // volvo.setCurrentGear(3);
  // volvo.setCurrentRPM(3000);
  // cout << "currenRPM: " << volvo.getCurrentRPM() << endl;

  while (true)
  {

    std::this_thread::sleep_for(500ms);
    ReadMessage(sockat_can, fr);

    // cout << "engCAN: " << hex << fr.data[0] << "  " << int(fr.data[0]) <<
    // endl;
    // temp = fr.data[0];
    if (fr.id == 0xAAA)
    {
      volvo.setEngineState(fr.data[0]);
      volvo.setCurrentGear(fr.data[1]);

      if (fr.data[1] == 3)
      {
        volvo.moveForward();
        cout << "Move Forward" << endl;
      }
      else if (fr.data[1] == 0)
      {
        volvo.moveRearward();
        cout << "Move Rearward" << endl;
      }
      if (fr.data[2] == 0)
        temp = 0;
      else if (fr.data[2] == 1)
        temp = 10;
      else if (fr.data[2] == 2)
        temp = 20;
      else if (fr.data[2] == 3)
        temp = 30;
      else if (fr.data[2] == 4)
        temp = 40;
      else if (fr.data[2] == 5)
        temp = 50;
      else if (fr.data[2] == 6)
        temp = 60;
      else if (fr.data[2] == 7)
        temp = 70;
      else if (fr.data[2] == 8)
        temp = 80;
      else if (fr.data[2] == 9)
        temp = 90;

      volvo.setCurrentRPM(temp);
      cout << "--------------------------" << endl;
      cout << "currenRPM: " << volvo.getCurrentRPM() << endl;
      cout << "carSpeed: " << volvo.getCarSpeed() << endl;
      cout << "DGear: " << volvo.getDGear() << endl;
      cout << "InputGear: " << volvo.getCurrentGear() << endl;
      cout << "--------------------------" << endl;
    }
  }

  /*
   cout << int(fr.data[0]) << " " << int(fr.data[1]) << " " << int(fr.data[2])
        << " " << int(fr.data[3]) << " " << int(fr.data[4]) << " "
        << int(fr.data[5]) << " " << int(fr.data[6]) << " " << int(fr.data[7])
        << endl;
        */
}