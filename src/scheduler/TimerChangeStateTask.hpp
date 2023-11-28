#ifndef __TIMER_CHANGE_STATE_TASK__
#define __TIMER_CHANGE_STATE_TASK__

#include "Task.hpp"
#include "StateManager.hpp"

class TimerChangeStateTask : public Task
{
private:
    StateManager* sm;
    State nextState;
public:
    TimerChangeStateTask(StateManager* sm, State nextState);
    ~TimerChangeStateTask();
    void tick();
    void init(unsigned int period);
};


#endif