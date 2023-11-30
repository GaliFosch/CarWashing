#include "TemperatureTask.hpp"

TemperatureTask::TemperatureTask(unsigned int time, StateManager *sm, TemperatureSensor *tS, double temperature, Mode mode):
    SensorTask(time, sm),
    tS(tS),
    temp(temperature),
    mode(mode)
{
}

boolean TemperatureTask::isInState(){
    if(mode == GREATER){
        return tS->read()>=temp;
    }else{
        return tS->read()<=temp;
    }
}

