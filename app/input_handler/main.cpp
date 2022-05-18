#include "canmessage.h"
#include "socketcan_cpp.h"
#include "socketcansetup.h"
#include "common_datatypes.h"
#include <curses.h>
#include <iostream>

#include <chrono> // std::chrono::microseconds
#include <thread>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  int ch = 0;
  nodelay(stdscr, TRUE);

  int const esc_key = 27;

  scpp::SocketCan sockat_can;
  InitSocketcan(sockat_can);

  CanMessage can_msg;

  while (ch != esc_key) {

    if ((ch = getch()) == ERR) {
    }
    if (ch == keyboard_common_input::EXIT) {
      bool run = true;
      while (run) {
        for (int i = 0; i < 100; i++) {
          can_msg.SetFrame(keyboard_input::THROTTLE_0);
          SendMessage(sockat_can, can_msg.frame);
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        for (int i = 0; i < 10; i++) {
          can_msg.SetFrame(keyboard_input::GEAR_PARK);
          SendMessage(sockat_can, can_msg.frame);
          std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        can_msg.SetFrame(keyboard_input::START_STOP);
        can_msg.SetFrame(ch);
        SendMessage(sockat_can, can_msg.frame);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        run = false;
        exit(-1);
      }
    } else {
      can_msg.SetFrame(ch);
      SendMessage(sockat_can, can_msg.frame);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }

  endwin();

  return 0;
}
