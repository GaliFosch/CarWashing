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
    PartManager* partManager;
    Scheduler* scheduler;
public:
    StateManager(State initialState);
    ~StateManager();
    void init();
    State getState();
    Scheduler* getScheduler();
    int changeState(State nextState);
};

#endif