#include <curses.h>
#include <iostream>
#include "checkInput.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int ch = 0;
    nodelay(stdscr, TRUE);
    for (;;)
    {
        if ((ch = getch()) == ERR)
        {
        }
        else
        {
            if (checkInput(ch) != -1) {
                //Below code to be replaced with message handler
                std::cout << "Input is " << ch << std::endl;
            } else {
                std::cout << "Invalid input!" << std::endl;
            } 
        }
    }
    endwin();
    return 0;
}