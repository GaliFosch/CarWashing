#include "ScedulerImpl.hpp"

#include <TimerOne.h>

volatile bool timerFlag;

void timeHandler(void)
{
    timerFlag = true;
}

ScedulerImpl::ScedulerImpl()
{
}

ScedulerImpl::~ScedulerImpl() {}

void ScedulerImpl::init(unsigned int basePeriod)
{
    this->period = basePeriod;
}

bool ScedulerImpl::addTask(Task *task) {
    if(numTasks < MAX_TASKS){
        this->taskArray[numTasks] = task;
        numTasks++;
        return true;
    }
    return false;
}
void ScedulerImpl::clearTasks() {
    numTasks = 0;
}
void ScedulerImpl::scedule() {
    while (!timerFlag){}
    timerFlag = false;

    for(int i=0; i<numTasks; i++){
        if(taskArray[i]->updateAndCheckTime(period)){
            taskArray[i]->tick();
        }
    }
}