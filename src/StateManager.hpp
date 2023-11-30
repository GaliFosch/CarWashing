#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include "scheduler/Scheduler.hpp"

boolean detectedProblem = false;

enum class State: int{
    SLEEP,
    CAR_DETECTED,
    CAR_ENTERING,
    WAITING_USER_INPUT,
    WASHING,
    MALFUNCTIONING,
    CAR_LEAVING
};

class StateManager
{
private:
    Scheduler* scheduler;
    State currState;
    State nextState;
    bool mustChangeState;
public:
    StateManager();
    void init();
    void changeState();
    void step();
    State getState();
};

#endif