#include "PIRTask.hpp"

PIRTask::PIRTask(unsigned int time, PIRSensor* pir, StateManager* sm) : SensorTask(time, sm), pir(pir)
{
}

boolean PIRTask::isInState(){
    return pir->read()>0;
}