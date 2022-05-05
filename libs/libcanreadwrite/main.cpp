#include <curses.h>
#include <iostream>
#include "checkinput.h"
#include "socketcan_cpp.h"
#include "canmessage.h"
#include "socketcansetup.h"



int main()
{
    scpp::SocketCan sockat_can;
    InitSocketcan(sockat_can);

    scpp::CanFrame fr;

    while (true)
    {
        ReadMessage(sockat_can, fr);
        printf("len %d byte, id: %d, data: %02x %02x %02x %02x %02x %02x %02x %02x  \n", fr.len, fr.id, 
                        fr.data[0], fr.data[1], fr.data[2], fr.data[3],
                        fr.data[4], fr.data[5], fr.data[6], fr.data[7]);
    }

    return 0;
}