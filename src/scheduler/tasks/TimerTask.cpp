#include "TimerTask.hpp"

TimerTask::TimerTask(unsigned int time, StateManager *sm) : SensorTask(time, sm)
{
}

boolean TimerTask::isInState(){
    return true;
}