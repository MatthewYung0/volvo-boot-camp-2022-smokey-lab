#pragma once
#include "socketcan_cpp.h"

void InitSocketcan(scpp::SocketCan &sockat_can);
void SendMessage(scpp::SocketCan &sockat_can, scpp::CanFrame &fr);
void ReadMessage(scpp::SocketCan &sockat_can, scpp::CanFrame &fr);