#ifndef __TASK__
#define __TASK__

class Task
{
protected:
    unsigned int period;
    unsigned int timeCounter;
public:
    virtual void init(unsigned int period);
    bool updateAndCheckTime(unsigned int time);
    virtual void tick() = 0;
};

void Task::init(unsigned int period){
    period = period;
}

bool Task::updateAndCheckTime(unsigned int time){
    timeCounter+=time;
    if(timeCounter>=period){
        timeCounter = 0;
        return true;
    }
    return false;
}

#endif