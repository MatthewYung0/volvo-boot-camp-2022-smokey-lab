#include "socketcansetup.h"
#include "canmessage.h"

const std::string can_network_name = "engineCAN";

void InitSocketcan(scpp::SocketCan &sockat_can) {
    if (sockat_can.open(can_network_name) != scpp::STATUS_OK) {
        printf("Cannot open can socket.\nCheck wether the CAN interface is up.\n");
        exit (-1);
    }
}

void SendMessage(scpp::SocketCan &sockat_can, scpp::CanFrame &fr) {
    auto write_sc_status = sockat_can.write(fr);
    if (write_sc_status != scpp::STATUS_OK)
        printf("something went wrong on socket write, error code : %d \n", int32_t(write_sc_status));
    else
        printf("Message was written to the socket \n");
}

void ReadMessage(scpp::SocketCan &sockat_can, scpp::CanFrame &fr) {
    if (sockat_can.read(fr) == scpp::STATUS_OK) {
    } else {
        for (size_t i = 0; i < 9999; i++); //STUPID SLEEP?
    }
}
