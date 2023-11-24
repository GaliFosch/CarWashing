#include "Sceduler.hpp"

#include <TimerOne.h>

volatile bool timerFlag;

void timeHandler(void)
{
    timerFlag = true;
}

Sceduler::Sceduler()
{
}

Sceduler::~Sceduler() {}

void Sceduler::init(unsigned int basePeriod)
{
    this->period = basePeriod;
}

bool Sceduler::addTask(Task *task) {
    if(numTasks < MAX_TASKS){
        this->taskArray[numTasks] = task;
        numTasks++;
        return true;
    }
    return false;
}
void Sceduler::clearTasks() {
    numTasks = 0;
}
void Sceduler::scedule() {
    while (!timerFlag){}
    timerFlag = false;

    for(int i=0; i<numTasks; i++){
        if(taskArray[i]->updateAndCheckTime(period)){
            taskArray[i]->tick();
        }
    }
}