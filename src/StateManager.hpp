#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include <avr/sleep.h>

#include "scheduler/Scheduler.hpp"
#include "components/ComponentsManager.hpp"

enum class State: int{
    SLEEP,
    CAR_DETECTED,
    CAR_ENTERING,
    WAITING_USER_INPUT,
    WASHING,
    MALFUNCTIONING,
    CAR_LEAVING
};

class StateManager
{
private:
    boolean detectedProblem = false;
    Scheduler* scheduler;
    State currState;
    State nextState;
    bool mustChangeState;

    ComponentsManager *compManager = ComponentsManager::getInstance();

    Task* blink2;
    Task* pir;
    Task* timerTask;
    Task* proxTask1;
    Task* buttonTask;
    Task* progBarTask;
    Task* tempTask;
    Task* checkMaintenanceTask;
    Task* proxTask2;

    void sleep();
public:
    StateManager();
    void init();
    void changeState(State nextState);
    void step();
    State getState();
    void signalProblem();
};

#endif