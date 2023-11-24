#include "StateManager.hpp"

StateManager::StateManager(State initialState, Sceduler *sceduler) : currState(initialState), sceduler(sceduler)
{
    partManager = PartManager::getInstance();
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
        partManager->closeGate();
        partManager->getLed(2)->turnOff();
        break;

    case WAITING:
        partManager->getLed(0)->turnOn();
        partManager->print("Welcome");
        break;

    case ENETERING:
        partManager->getLed(0)->turnOff();
        partManager->openGate();
        partManager->print("Proceed to the Washing Area");
        break;

    case WAITING_INPUT:
        partManager->closeGate();
        partManager->getLed(1)->turnOn();
        partManager->print("Ready to Wash");
        break;

    case WASHING:
        break;

    case LEAVE:
        partManager->getLed(1)->turnOff();
        partManager->getLed(2)->turnOn();
        partManager->print("Washing complete, you can leave the area");
        break;

    default:
        break;
    }
    return 1;
}