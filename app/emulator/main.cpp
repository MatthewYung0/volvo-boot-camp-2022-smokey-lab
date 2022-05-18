#include "emulator.h"
#include <iostream>
#include <sstream>

#include "socketcan_cpp.h"
#include "socketcansetup.h"

#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace std;

std::mutex rw_lock;
std::condition_variable cv;
bool read_msg = false;
bool write_msg = false;

void read_message(scpp::SocketCan &_socket_can, scpp::CanFrame &_in_fr);

int main() {

  scpp::SocketCan socket_can;
  InitSocketcan(socket_can);
  scpp::CanFrame in_fr, out_fr;

  // init input frame
  in_fr.id = USER_FRAME_ID;
  in_fr.len = 8;
  in_fr.flags = 0;
  for (int i = 0; i < 8; i++) {
    in_fr.data[i] = 0;
  }

  // init emulator frame
  out_fr.id = ENGINE_FRAME_ID;
  out_fr.len = 8;
  out_fr.flags = 0;
  for (int i = 0; i < 8; i++) {
    out_fr.data[i] = 0;
  }

  out_fr.len = 8;
  out_fr.id = ENGINE_FRAME_ID;

  int rpm = 650;

  Emulator volvo;

  std::thread read_from_bus(read_message, std::ref(socket_can),
                            std::ref(in_fr));
  read_from_bus.detach();

  {
    std::lock_guard<std::mutex> lk(rw_lock);
    read_msg = true;
  }
  cv.notify_one();

  while (true) {
    std::unique_lock<std::mutex> lk(rw_lock);
    cv.wait(lk, [] { return write_msg; });
    if (in_fr.id == USER_FRAME_ID) {
      write_msg = false;

      volvo.setEngineState(in_fr.data[user_frame_data_partition::IGNITION]);
      volvo.setCurrentGear(in_fr.data[user_frame_data_partition::LEVER]);

      if (in_fr.data[user_frame_data_partition::LEVER] == gear_lever::DRIVE) {
        volvo.moveForward();
      } else if (in_fr.data[user_frame_data_partition::LEVER] ==
                 gear_lever::REAR) {
        volvo.moveRearward();
      }

      volvo.setCurrentRPM(
          int(in_fr.data[user_frame_data_partition::PEDAL_POS]));
      cout << "--------------------------" << endl;
      cout << "Pedal value: "
           << int(in_fr.data[user_frame_data_partition::PEDAL_POS]) << endl;
      cout << "currenRPM: " << volvo.getCurrentRPM() << endl;
      cout << "carSpeed: " << volvo.getCarSpeed() << endl;
      cout << "DGear: " << volvo.getDGear() << endl;
      cout << "InputGear: " << volvo.getCurrentGear() << endl;
      cout << "--------------------------" << endl;

      out_fr.data[engine_frame_data_partition::VELOCITY] = volvo.getCarSpeed();
      out_fr.data[engine_frame_data_partition::LEVER] = volvo.getCurrentGear();
      out_fr.data[engine_frame_data_partition::GEAR] = volvo.getDGear();
      out_fr.data[engine_frame_data_partition::IGNITION] =
          volvo.getEngineState();

      rpm = volvo.getCurrentRPM();

      out_fr.data[4] = ((rpm & 0xf000) >> 12);
      out_fr.data[5] = ((rpm & 0xf00) >> 8);
      out_fr.data[6] = ((rpm & 0xf0) >> 4);
      out_fr.data[7] = ((rpm & 0xf) >> 0);

      SendMessage(socket_can, out_fr);
      if (in_fr.data[user_frame_data_partition::EXIT] == 113) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        exit(-1);
      }
      lk.unlock();
    }
    read_msg = true;
    cv.notify_one();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  return 0;
}

void read_message(scpp::SocketCan &_socket_can, scpp::CanFrame &_in_fr) {
  while (true) {
    std::unique_lock<std::mutex> lk(rw_lock);
    cv.wait(lk, [] { return read_msg; });
    ReadMessage(_socket_can, _in_fr);
    read_msg = false;
    write_msg = true;
    lk.unlock();
    cv.notify_one();
    if (_in_fr.data[user_frame_data_partition::EXIT] == keyboard_common_input::EXIT) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      exit(-1);
    }
  }
}