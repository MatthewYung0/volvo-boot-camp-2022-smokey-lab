#include <iostream>
#include "socketcan_cpp.h"
#include "can_message.h"
#include "init_socketcan.h"



int main() {

    scpp::SocketCan sockat_can;
    InitSocketcan(sockat_can);
    
    CanMessage can_msg;

    while (true) {

        int input{};
        std::cout << "User Input: ";
        std::cin >> input;

        can_msg.SetFrame(input);

        SendMessage(sockat_can, can_msg);
    
    }

    return 0;
}