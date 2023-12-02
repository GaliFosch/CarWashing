#ifndef __SENSOR_TASK__
#define __SENSOR_TASK__

#include "TimeInStateTask.hpp"
#include "StateManager.hpp"

class SensorTask : public TimeInStateTask
{
protected:
    virtual boolean isInState() = 0;
    StateManager* sm;
    State state;
public:
    SensorTask(unsigned int time, StateManager* sm, State state): TimeInStateTask(time), sm(sm), state(state) {}
    void exec(){
        sm->changeState(state);
    }
};

#endif