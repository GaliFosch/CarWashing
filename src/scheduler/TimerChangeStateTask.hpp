#ifndef __TIMER_CHANGE_STATE_TASK__
#define __TIMER_CHANGE_STATE_TASK__

#include "TimeInStateTask.hpp"
#include "StateManager.hpp"

class TimerChangeStateTask : public TimeInStateTask
{
private:
    StateManager *sm;
    State nextState;
    unsigned int time;

public:
    TimerChangeStateTask(StateManager *sm, State nextState, unsigned int time);
    ~TimerChangeStateTask();
    boolean isInState();
    void tick();
    void init(unsigned int period);
};

#endif