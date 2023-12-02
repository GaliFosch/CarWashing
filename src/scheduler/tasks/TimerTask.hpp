#ifndef __TIMER_TASK__
#define __TIMER_TASK__

#include "SensorTask.hpp"

class TimerTask : public SensorTask
{
public:
    TimerTask(unsigned int time, StateManager* sm, State state);
    boolean isInState();
};


#endif