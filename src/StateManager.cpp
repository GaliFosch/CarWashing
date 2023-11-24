#include "StateManager.hpp"

StateManager::StateManager(State initialState, Sceduler *sceduler) : currState(initialState), sceduler(sceduler)
{
}

StateManager::~StateManager()
{

}

State StateManager::getState()
{
    return currState;
}

int StateManager::changeState(State nextState)
{
    currState = nextState;
    switch (nextState)
    {
    case SLEEP:
        break;

    case WAITING:
        break;

    case ENETERING:
        break;

    case WAITING_INPUT:
        break;

    case WASHING:
        break;

    case LEAVE:
        break;

    default:
        break;
    }
    return 1;
}