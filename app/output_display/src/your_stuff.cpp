#include <thread>
#include <iostream>
#include <pthread.h>
#include <bits/stdc++.h>
#include <chrono>
#include "your_stuff.h"
#include "can_common.h"
//#include "ignition_start_rpm_display.h"

// void ignition_start_speed_display() {
//     for (int start_speed = 0; start_speed < 255; start_speed++) {
//         this->InstrumentCluster.setSpeed(start_speed);
//     }
//     for (int end_speed = 255; end_speed > 0; end_speed--) {
//         this->InstrumentCluster.setSpeed(end_speed);
//     }
// }

void yourStuff::YouHaveJustRecievedACANFrame(const canfd_frame * const _frame) {

    if (_frame->can_id == 0xBBB) {
        this->InstrumentCluster.ignite(_frame->data[3]);
        this->InstrumentCluster.setRPM((_frame->data[4] << 12) | (_frame->data[5]) << 8 | (_frame->data[6]) << 4 | (_frame->data[7]) << 0);
        this->InstrumentCluster.setSpeed(_frame->data[0]);
        this->InstrumentCluster.setFuelGauges(0);
        this->InstrumentCluster.setOilTemperatureGauges(180);
        this->InstrumentCluster.setGear(_frame->data[2]);
        this->InstrumentCluster.setGearPindle_int(_frame->data[1]);
        this->InstrumentCluster.setTXT("STARTED");
    }


/******************************* ANYTHING BELOW THIS LINE IS JUST BORING STUFF *******************************/

yourStuff::yourStuff(const std::string &_ifName, QObject *_vs) {
    if(!(this->CANReader.open(_ifName))) exit(-1);//emit die();

    this->InstrumentCluster.init(_vs);

    this->startTimer(1);
}

bool yourStuff::run() {
    bool ret = true;
    CANOpener::ReadStatus status = CANOpener::ReadStatus::OK;
    canfd_frame frame;
    this->CANReader.read(&frame);
    /*while*/if (status == CANOpener::ReadStatus::OK) {
        this->YouHaveJustRecievedACANFrame(&frame);
    }
    if (status == CANOpener::ReadStatus::ERROR) ret = false;
    else if (status == CANOpener::ReadStatus::NAVAL ||
             status == CANOpener::ReadStatus::ENDOF) this->Counter++;
    else   this->Counter = 0;
    //if (this->Counter > 200) ret = false;
    return ret;
}

void yourStuff::timerEvent(QTimerEvent*) {
    if(this->run());
    else {
//    emit this->die();
        exit(-1);
    }

}

