#include <curses.h>
#include <iostream>

int checkInput(int const &input) {

    int output = -1;

    if (input == 113 || input == 115 || input == 100 || input == 114 || input == 110 ||
        input == 112 || input == 48  || input == 49  || input == 50  || input == 51  ||
        input == 52  || input == 53  || input == 54  || input == 55  || input == 56  ||
        input == 57  || input == 258 || input == 259) {
            output = input;
        }
    return output;

/*  |   |key|command
    |---|------------------------------------|
    | q | quit applications           (113)  |
    | s | start/stop engine           (115)  |
    | d | gear drive                  (100)  |
    | r | gear rear                   (114)  |
    | n | gear neutral                (110)  |
    | p | gear park                   (112)  |
    | up arrow | pedal down           (259)  |
    | down arrow | pedal up           (258)  |
    | 0 ... 9 | throttle 0 - 90 % (48 - 57)  |*/
    
}

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