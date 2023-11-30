#include "StateManager.hpp"

#include "scheduler/SchedulerImpl.hpp"
#include "components/ComponentsManager.hpp"

ComponentsManager *compManager = ComponentsManager::getInstance();

StateManager::StateManager()
{
    scheduler = new SchedulerImpl;
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
    if (mustChangeState)
    {
        if (detectedProblem && currState == State::WASHING)
        {
            currState = State::MALFUNCTIONING;
        }
        else
        {
            currState = nextState;
        }
        switch (currState)
        {
            case State::SLEEP:
                compManager->closeGate();
                compManager->getLed3()->turnOff();
                nextState= State::CAR_DETECTED;
                break;
            case State::CAR_DETECTED:
                compManager->getLed1()->turnOn();
                compManager->print("Welcome!");
                nextState = State::CAR_ENTERING;
                break;
            case State::CAR_ENTERING:
                compManager->getLed1()->turnOff();
                compManager->print("Proceed to the Washing Area");
                compManager->openGate();
                nextState = State::WAITING_USER_INPUT;
                break;
            case State::WAITING_USER_INPUT:
                compManager->getLed2()->turnOff();
                compManager->closeGate();
                compManager->print("Ready to Wash");
                nextState = State::WASHING;
                break;
            case State::WASHING:
                nextState = State::CAR_LEAVING;
                break;
            case State::MALFUNCTIONING:
                nextState = State::WASHING;
                break;
            case State::CAR_LEAVING:
                compManager->getLed2()->turnOff();
                compManager->getLed3()->turnOn();
                compManager->print("Washing complete, you can leave the area");
                nextState=State::SLEEP;
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