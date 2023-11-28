#include "TimerChangeStateTask.hpp"

static boolean executed;

TimerChangeStateTask::TimerChangeStateTask(StateManager *sm, State nextState) : sm(sm), nextState(nextState)
{
}

TimerChangeStateTask::~TimerChangeStateTask() {}

void TimerChangeStateTask::tick()
{
    if(executed){
        sm->changeState(nextState);
        executed = true;
    }
}

void TimerChangeStateTask::init(unsigned int period){
    this->Task::init(period);
    executed = false;
}