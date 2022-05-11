#include <iostream>
#include "socketcansetup.h"
#include "socketcan_cpp.h"
#include <curses.h>


int main () {
    scpp::SocketCan sockat_can;
    InitSocketcan(sockat_can);
    scpp::CanFrame output_frame;

    while(true) {
       
    output_frame.id = 0xBBB;
    output_frame.len = 8;
    for (int i = 0; i < 8; ++i)
        output_frame.data[i] = std::rand() % 256;

    SendMessage(sockat_can, output_frame);
    
    }
    return 0;
}