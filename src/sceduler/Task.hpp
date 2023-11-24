#ifndef __TASK__
#define __TASK__

class Task
{
private:
    unsigned int period;
    unsigned int timeCounter;
public:
    Task();
    ~Task();
    virtual void init(unsigned int period);
    bool updateAndCheckTime(unsigned int time);
    virtual void tick();
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