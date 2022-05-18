#include "your_stuff.h"
#include "can_common.h"
#include "common_datatypes.h"
#include <bits/stdc++.h>
#include <iostream>

void yourStuff::YouHaveJustRecievedACANFrame(const canfd_frame *const _frame) {

  if (_frame->can_id == ENGINE_FRAME_ID) {
    this->InstrumentCluster.ignite(
        _frame->data[engine_frame_data_partition::IGNITION]);
    this->InstrumentCluster.setRPM(
        (_frame->data[engine_frame_data_partition::RPM_1] << 12) |
        (_frame->data[engine_frame_data_partition::RPM_2]) << 8 |
        (_frame->data[engine_frame_data_partition::RPM_3]) << 4 |
        (_frame->data[engine_frame_data_partition::RPM_4]) << 0);
    this->InstrumentCluster.setSpeed(
        _frame->data[engine_frame_data_partition::VELOCITY]);
    if (_frame->data[engine_frame_data_partition::IGNITION]) {
      this->InstrumentCluster.setFuelGauges(180);
      this->InstrumentCluster.setOilTemperatureGauges(110);
      this->InstrumentCluster.setTemperatureGauges(130);
    } else {
      this->InstrumentCluster.setFuelGauges(0);
      this->InstrumentCluster.setOilTemperatureGauges(0);
      this->InstrumentCluster.setTemperatureGauges(0);
    }
    this->InstrumentCluster.setGear(
        _frame->data[engine_frame_data_partition::GEAR]);
    this->InstrumentCluster.setGearPindle_int(
        _frame->data[engine_frame_data_partition::LEVER]);
    this->InstrumentCluster.setTXT("TEAM SMOKEY ALLL DA WAAAY");
  }
}

/******************************* ANYTHING BELOW THIS LINE IS JUST BORING STUFF
 * *******************************/

yourStuff::yourStuff(const std::string &_ifName, QObject *_vs) {
  if (!(this->CANReader.open(_ifName)))
    exit(-1); // emit die();

  this->InstrumentCluster.init(_vs);
  this->Counter = 0;
  this->startTimer(1);
}

bool yourStuff::run() {
  bool ret = true;
  canfd_frame frame;
  CANOpener::ReadStatus status = this->CANReader.read(&frame);
  /*while*/ if (status == CANOpener::ReadStatus::OK) {
    this->YouHaveJustRecievedACANFrame(&frame);
  }
  if (status == CANOpener::ReadStatus::ERROR)
    ret = false;
  else if (status == CANOpener::ReadStatus::NAVAL ||
           status == CANOpener::ReadStatus::ENDOF)
    this->Counter++;
  else
    this->Counter = 0;
  if (this->Counter > 1000)
    ret = false;
  return ret;
}

void yourStuff::timerEvent(QTimerEvent *) {
  if (this->run())
    ;
  else {
    //    emit this->die();
    exit(-1);
  }
}
