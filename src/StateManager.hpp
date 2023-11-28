#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include "scheduler/Scheduler.hpp"
#include "PartManager.hpp"

typedef enum{
    SLEEP,
    WAITING,
    ENETERING,
    WAITING_INPUT,
    WASHING,
    LEAVE
} State;

class StateManager
{
private:
    State currState;
    Scheduler* scheduler;
    PartManager* partManager;
public:
    StateManager(State initialState, Scheduler* scheduler);
    ~StateManager();
    State getState();
    int changeState(State nextState);
};

#endif