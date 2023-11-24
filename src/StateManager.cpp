#include "StateManager.hpp"

StateManager::StateManager(State initialState):currState(initialState)
{
}

StateManager::~StateManager(){

}
State StateManager::getState(){
    return currState;
}

int StateManager::changeState(State nextState){
    currState = nextState;
    return 1;
}