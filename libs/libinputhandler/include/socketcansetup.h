#pragma once
#include "socketcan_cpp.h"
#include "canmessage.h"

void InitSocketcan(scpp::SocketCan &sockat_can);
void SendMessage(scpp::SocketCan &sockat_can, CanMessage &can_msg);
void ReadMessage(scpp::SocketCan &sockat_can, scpp::CanFrame &fr);