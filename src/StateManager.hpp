#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include "sceduler/Sceduler.hpp"

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
    Sceduler* sceduler;
public:
    StateManager(State initialState, Sceduler* sceduler);
    ~StateManager();
    State getState();
    int changeState(State nextState);
};

#endif