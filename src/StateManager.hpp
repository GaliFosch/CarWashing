#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

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
public:
    StateManager(State initialState);
    ~StateManager();
    State getState();
    int changeState(State nextState);
};

#endif