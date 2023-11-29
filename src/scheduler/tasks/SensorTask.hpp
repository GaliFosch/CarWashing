#ifndef __SENSOR_TASK__
#define __SENSOR_TASK__

#include "TimeInStateTask.hpp"
#include "StateManager.hpp"

class SensorTask : public TimeInStateTask
{
protected:
    virtual boolean isInState() = 0;
    StateManager* sm;
public:
    SensorTask(unsigned int time, StateManager* sm): TimeInStateTask(time), sm(sm) {}
    void exec(){
        sm->changeState();
    }
};

#endif