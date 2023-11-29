#include "TimerChangeStateTask.hpp"

TimerChangeStateTask::TimerChangeStateTask(StateManager *sm, State nextState, unsigned int time) : 
    sm(sm), 
    nextState(nextState), 
    time(time)
{
}

TimerChangeStateTask::~TimerChangeStateTask() {}

void TimerChangeStateTask::tick()
{
    this->TimeInStateTask::tick();
    sm->changeState(nextState);
}

void TimerChangeStateTask::init(unsigned int period)
{
    this->Task::init(period);
}

boolean TimerChangeStateTask::isInState()
{
    return true;
}