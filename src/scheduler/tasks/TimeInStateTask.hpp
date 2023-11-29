#ifndef __TIME_IN_STATE_TASK__
#define __TIME_IN_STATE_TASK__

#include "Task.hpp"

class TimeInStateTask : public Task
{
protected:
    unsigned int timeInState;

public:
    virtual boolean isInState() = 0;
    virtual void init(unsigned int period)
    {
        this->Task::init(period);
        this->timeInState = 0;
    }
    virtual void tick()
    {
        if (isInState())
        {
            this->timeInState += period;
        }
        else
        {
            this->timeInState = 0;
        }
    }
};

#endif