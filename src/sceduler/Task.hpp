#ifndef __TASK__
#define __TASK__

class Task
{
protected:
    unsigned int period;
    unsigned int timeCounter;

public:
    virtual void init(unsigned int period)
    {
        period = period;
    }
    bool updateAndCheckTime(unsigned int time)
    {
        timeCounter += time;
        if (timeCounter >= period)
        {
            timeCounter = 0;
            return true;
        }
        return false;
    }
    virtual void tick() = 0;
};


#endif