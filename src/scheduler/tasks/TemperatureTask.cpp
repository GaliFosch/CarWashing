#include "TemperatureTask.hpp"
#include "serial/MsgService.hpp"

TemperatureTask::TemperatureTask(unsigned int time, StateManager *sm, TemperatureSensor *tS, double temperature, Mode mode):
    SensorTask(time, sm),
    tS(tS),
    temp(temperature),
    mode(mode)
{
}

boolean TemperatureTask::isInState(){
    double read = tS->read();
    MsgService.sendMsg("t-"+ String(read,2));
    if(mode == GREATER){
        return read>=temp;
    }else{
        return read<=temp;
    }
}

void TemperatureTask::exec(){
    SensorTask::exec();
    MsgService.sendMsg("m");
    sm->signalProblem();
}

