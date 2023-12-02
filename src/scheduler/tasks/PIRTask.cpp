#include "PIRTask.hpp"

PIRTask::PIRTask(unsigned int time, PIRSensor* pir, StateManager* sm, State state) : SensorTask(time, sm, state), pir(pir)
{
}

boolean PIRTask::isInState(){
    return pir->read()>0;
}