#include "StateManager.hpp"

#include "scheduler/SchedulerImpl.hpp"
#include "components/ComponentsManager.hpp"

#include "scheduler/tasks/BlinkTask.hpp"
#include "scheduler/tasks/PIRTask.hpp"
#include "scheduler/tasks/ProximityTask.hpp"
#include "scheduler/tasks/ButtonTask.hpp"
#include "scheduler/tasks/TimerTask.hpp"
#include "scheduler/tasks/TemperatureTask.hpp"

#define N1 2000
#define N2 2000
#define N3 10000
#define N4 2000

#define T_TIME 500
#define MAX_TEMP 30
#define DIST 10

ComponentsManager *compManager = ComponentsManager::getInstance();

Task* blink2;
Task* pir;
Task* proxTask1;
Task* buttonTask;
//Task* progBarTask;
Task* timerTask;
Task* tempTask;
Task* proxTask2;

StateManager::StateManager()
{
    scheduler = new SchedulerImpl;
}

void StateManager::init()
{
    blink2 = new BlinkTask(compManager->getLed2());
    blink2->init(100);
    this->scheduler->addTask(blink2);
    pir = new PIRTask(N1, compManager->getPirSensor(), this);
    pir->init(100);
    this->scheduler->addTask(pir);
    proxTask1 = new ProximityTask(N2, this, compManager->getProximitySensor(), DIST, ProximityTask::Mode::LOWER);
    proxTask1->init(500);
    this->scheduler->addTask(proxTask1);
    buttonTask = new ButtonTask(this, compManager->getButton());
    buttonTask->init(200);
    this->scheduler->addTask(buttonTask);

    timerTask = new TimerTask(N3, this);
    timerTask->init(100);
    this->scheduler->addTask(timerTask);
    tempTask = new TemperatureTask(T_TIME, this, compManager->getTemperatureSensor(), MAX_TEMP, TemperatureTask::Mode::GREATER);
    tempTask->init(100);
    this->scheduler->addTask(tempTask);
    proxTask2 = new ProximityTask(N4, this, compManager->getProximitySensor(), DIST, ProximityTask::Mode::GREATER);
    proxTask2->init(500);
    this->scheduler->addTask(proxTask2);

    this->nextState = State::SLEEP;
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

                proxTask2->deactivate();
                //temporaneo
                buttonTask->activate();
                //----------

                nextState= State::CAR_DETECTED;
                break;
            case State::CAR_DETECTED:
                compManager->getLed1()->turnOn();
                compManager->print("Welcome!");

                //temporaneo
                buttonTask->deactivate();
                //----------
                pir->activate();

                nextState = State::CAR_ENTERING;
                break;
            case State::CAR_ENTERING:
                compManager->getLed1()->turnOff();
                compManager->print("Proceed to the Washing Area");
                compManager->openGate();
                
                pir->deactivate();
                blink2->activate();
                proxTask1->activate();

                nextState = State::WAITING_USER_INPUT;
                break;
            case State::WAITING_USER_INPUT:
                compManager->getLed2()->turnOff();
                compManager->closeGate();
                compManager->print("Ready to Wash");

                blink2->deactivate();
                proxTask1->deactivate();
                buttonTask->activate();

                nextState = State::WASHING;
                break;
            case State::WASHING:

                buttonTask->deactivate();
                blink2->activate();
                tempTask->activate();
                timerTask->activate();

                nextState = State::CAR_LEAVING;
                break;
            case State::MALFUNCTIONING:
                compManager->getLed2()->turnOff();
                compManager->print("Detected a Problem \n Please Wait");

                blink2->deactivate();
                tempTask->deactivate();
                timerTask->deactivate();
                //temporaneo
                buttonTask->activate();
                //----------
                nextState = State::WASHING;
                break;
            case State::CAR_LEAVING:
                compManager->getLed2()->turnOff();
                compManager->getLed3()->turnOn();
                compManager->print("Washing complete, you can leave the area");
                
                blink2->deactivate();
                tempTask->deactivate();
                timerTask->deactivate();
                proxTask2->activate();

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

void StateManager::signalProblem(){
    detectedProblem = true;
}