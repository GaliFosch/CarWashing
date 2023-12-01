#ifndef __TIME_IN_TASK__
#define __TIME_IN_TASK__

#include "Task.hpp"

class TimeInStateTask : public Task
{
private:
    unsigned int time;
    unsigned int counter;

protected:
    virtual boolean isInState() = 0;
    virtual void exec() = 0;

public:
    TimeInStateTask(unsigned int time) : time(time) {}
    void tick()
    {
        if (isInState())
            counter += period;
        else
            counter = 0;
        if (counter >= time)
        {
            exec();
            counter = 0;
        }
    }

    unsigned int getCurrTime()
    {
        return counter;
    }
    unsigned int getTime()
    {
        return time;
    }
};

#endif