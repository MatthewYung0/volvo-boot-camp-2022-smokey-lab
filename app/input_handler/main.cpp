#include "canmessage.h"
#include "socketcan_cpp.h"
#include "socketcansetup.h"
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
    can_msg.SetFrame(ch);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    SendMessage(sockat_can, can_msg.frame);
  }

  endwin();

  return 0;
}