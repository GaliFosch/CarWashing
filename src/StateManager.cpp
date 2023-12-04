#include "StateManager.hpp"

#include "serial/MsgService.hpp"

#include "scheduler/SchedulerImpl.hpp"
#include "scheduler/tasks/BlinkTask.hpp"
#include "scheduler/tasks/PIRTask.hpp"
#include "scheduler/tasks/ProximityTask.hpp"
#include "scheduler/tasks/ButtonTask.hpp"
#include "scheduler/tasks/TimerTask.hpp"
#include "scheduler/tasks/TemperatureTask.hpp"
#include "scheduler/tasks/ProgressBarTask.hpp"
#include "scheduler/tasks/CheckMaintenanceTask.hpp"

#define N1 500
#define N2 2000
#define N3 10000
#define N4 2000

#define T_TIME 1000
#define MAX_TEMP 30
#define DIST_ENT 0.05
#define DIST_OUT 0.15
#define TIMER 10000

#define START_WASHNG_MSG "w"
#define STOP_WASHNG_MSG "sw"

StateManager::StateManager()
{
    scheduler = new SchedulerImpl;
}

void StateManager::init()
{
    blink2 = new BlinkTask(compManager->getLed2());
    blink2->init(500);
    this->scheduler->addTask(blink2);

    pir = new PIRTask(N1, compManager->getPirSensor(), this, State::CAR_ENTERING);
    pir->init(100);
    this->scheduler->addTask(pir);

    timerTask = new TimerTask(TIMER, this, State::SLEEP);
    timerTask->init(TIMER);
    this->scheduler->addTask(timerTask);

    proxTask1 = new ProximityTask(N2, this, State::WAITING_USER_INPUT, compManager->getProximitySensor(), DIST_ENT, ProximityTask::Mode::LOWER);
    proxTask1->init(500);
    this->scheduler->addTask(proxTask1);

    buttonTask = new ButtonTask(this, compManager->getButton(), State::WASHING);
    buttonTask->init(200);
    this->scheduler->addTask(buttonTask);

    progBarTask = new ProgressBarTask(N3, this, State::CAR_LEAVING);
    this->scheduler->addTask(progBarTask);

    tempTask = new TemperatureTask(T_TIME, this, State::MALFUNCTIONING, compManager->getTemperatureSensor(), MAX_TEMP, TemperatureTask::Mode::GREATER);
    tempTask->init(100);
    this->scheduler->addTask(tempTask);

    checkMaintenanceTask = new CheckMaintenanceTask(this, State::WASHING);
    checkMaintenanceTask->init(100);
    this->scheduler->addTask(checkMaintenanceTask);

    proxTask2 = new ProximityTask(N4, this, State::SLEEP, compManager->getProximitySensor(), DIST_OUT, ProximityTask::Mode::GREATER);
    proxTask2->init(500);
    this->scheduler->addTask(proxTask2);

    this->changeState(State::SLEEP);
    this->scheduler->init(50);
}

void StateManager::changeState(State nextState)
{
    this->mustChangeState = true;
    this->nextState = nextState;
}

void StateManager::step()
{
    if (mustChangeState)
    {
        mustChangeState = false;
        this->currState = this->nextState;
        switch (currState)
        {
        case State::SLEEP:
            compManager->closeGate();
            compManager->getLed3()->turnOff();

            proxTask2->deactivate();
            pir->deactivate();
            timerTask->deactivate();
            sleep();
            this->changeState(State::CAR_DETECTED);
            break;
        case State::CAR_DETECTED:
            compManager->getLed1()->turnOn();
            compManager->print("Welcome!");

            pir->activate();
            timerTask->activate();

            break;
        case State::CAR_ENTERING:
            compManager->getLed1()->turnOff();
            compManager->print("Proceed to the Washing Area");
            compManager->openGate();

            pir->deactivate();
            timerTask->deactivate();
            blink2->activate();
            proxTask1->activate();

            break;
        case State::WAITING_USER_INPUT:
            compManager->getLed2()->turnOn();
            compManager->closeGate();
            compManager->print("Ready to Wash");

            blink2->deactivate();
            proxTask1->deactivate();
            buttonTask->activate();

            break;
        case State::WASHING:
            MsgService.sendMsg(START_WASHNG_MSG);

            buttonTask->deactivate();
            checkMaintenanceTask->deactivate();
            blink2->activate();
            tempTask->activate();
            progBarTask->activate();

            break;
        case State::MALFUNCTIONING:
            compManager->getLed2()->turnOff();
            compManager->print("Detected a Problem \n Please Wait");

            blink2->deactivate();
            tempTask->deactivate();
            progBarTask->deactivate();
            checkMaintenanceTask->activate();

            break;
        case State::CAR_LEAVING:
            MsgService.sendMsg(STOP_WASHNG_MSG);
            compManager->getLed2()->turnOff();
            compManager->getLed3()->turnOn();
            compManager->print("Washing complete, you can leave the area");

            blink2->deactivate();
            tempTask->deactivate();
            progBarTask->deactivate();
            proxTask2->activate();

            break;
        }
    }

    this->scheduler->scedule();
}

State StateManager::getState()
{
    return this->currState;
}

void StateManager::signalProblem()
{
    detectedProblem = true;
}

void wakeUp()
{
}

void StateManager::sleep()
{
    attachInterrupt(digitalPinToInterrupt(compManager->getPirSensor()->getPin()), wakeUp, RISING);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();

    detachInterrupt(digitalPinToInterrupt(compManager->getPirSensor()->getPin()));
}