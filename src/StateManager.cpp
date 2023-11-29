#include "StateManager.hpp"

#include "scheduler/TimerChangeStateTask.hpp"
#include "scheduler/SchedulerImpl.hpp"

StateManager::StateManager(State initialState) : 
    partManager(PartManager::getInstance())
{
    this->scheduler = new SchedulerImpl();
    this->currState = initialState;
}

StateManager::~StateManager()
{
}

void StateManager::init(){
    // metti Task dentro lo scheduler
}

State StateManager::getState()
{
    return currState;
}

Scheduler* StateManager::getScheduler(){
    return scheduler;
}

int StateManager::changeState(State nextState)
{
    currState = nextState;
    switch (nextState)
    {
    case SLEEP:
        partManager->closeGate();
        partManager->getLed3().turnOff();
    break;

    case WAITING:
        partManager->getLed1().turnOn();
        partManager->print("Welcome");
        break;

    case ENETERING:
        partManager->getLed1().turnOff();
        partManager->openGate();
        partManager->print("Proceed to the Washing Area");
        break;

    case WAITING_INPUT:
        partManager->closeGate();
        partManager->getLed2().turnOn();
        partManager->print("Ready to Wash");
        break;

    case WASHING:
        break;

    case LEAVE:
        partManager->getLed2().turnOff();
        partManager->getLed3().turnOn();
        partManager->print("Washing complete, you can leave the area");
        break;

    default:
        break;
    }
    return 1;
}