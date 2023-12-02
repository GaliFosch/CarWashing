#include "TimerTask.hpp"

TimerTask::TimerTask(unsigned int time, StateManager *sm, State state) : SensorTask(time, sm, state)
{
}

boolean TimerTask::isInState(){
    return true;
}