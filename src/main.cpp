#include <curses.h>
#include <iostream>

bool checkInput(int &input) {
    bool isValid = false;
    int array[4] = {97,119,100,115};
    for (int i = 0; i < 5; i++) {
        if (input == array[i]) {
            isValid = true;
            break;
        }
    }
    return isValid;
}

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int ch;
    nodelay(stdscr, TRUE);
    for (;;)
    {
        if ((ch = getch()) == ERR)
        {
        }
        else
        {
            if (checkInput(ch)) {
                std::cout << "Input is " << ch << std::endl;
            } else {
                std::cout << "Invalid input!" << std::endl;
            }
            
        }
    }
    std::cout << "Hello World!" << std::endl;
    endwin();
    return 0;
}