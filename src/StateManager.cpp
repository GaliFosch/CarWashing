#include "StateManager.hpp"

#include "scheduler/SchedulerImpl.hpp"
#include "components/ComponentsManager.hpp"

ComponentsManager* compManager;

StateManager::StateManager()
{
    scheduler = new SchedulerImpl;
    compManager = ComponentsManager::getInstance();
}

void StateManager::init()
{
    this->scheduler->init(50);
}

void StateManager::changeState()
{
    this->mustChangeState = true;
}

void StateManager::step()
{
    if(mustChangeState){
        currState = nextState;
        switch(currState){
            case State::SLEEP:
                break;
            case State::CAR_DETECTED: 
                break;
            case State::CAR_ENTERING: 
                break;
            case State::WAITING_USER_INPUT: 
                break;
            case State::WASHING: 
                break;
            case State::MALFUNCTIONING: 
                break;
            case State::CAR_LEAVING: 
                break;        
        }
        mustChangeState = false;
    }
    this->scheduler->scedule();
}

State StateManager::getState()
{
    return this->currState;
}