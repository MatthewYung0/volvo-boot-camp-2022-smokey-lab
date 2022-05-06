#include <curses.h>
#include <iostream>
#include "checkinput.h"
#include "socketcan_cpp.h"
#include "canmessage.h"
#include "socketcansetup.h"



int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int ch = 0;
    nodelay(stdscr, TRUE);

    scpp::SocketCan sockat_can;
    InitSocketcan(sockat_can);

    CanMessage can_msg;

    while (true)
    {
        if ((ch = getch()) == ERR)
        {
        }
        else
        {
            if (checkInput(ch) != -1) {
                can_msg.SetFrame(ch);
                SendMessage(sockat_can, can_msg);
                can_msg.ResetFrame();
            } else {
                std::cout << "Invalid input!" << std::endl;
            } 
        }
    }
    endwin();
    return 0;
}