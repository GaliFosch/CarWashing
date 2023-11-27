#include "SchedulerImpl.hpp"

#include <TimerOne.h>

volatile bool timerFlag;

void timeHandler(void)
{
    timerFlag = true;
}

SchedulerImpl::SchedulerImpl()
{
}

SchedulerImpl::~SchedulerImpl() {}

void SchedulerImpl::init(unsigned int basePeriod)
{
    this->period = basePeriod;
}

bool SchedulerImpl::addTask(Task *task) {
    if(numTasks < MAX_TASKS){
        this->taskArray[numTasks] = task;
        numTasks++;
        return true;
    }
    return false;
}
void SchedulerImpl::clearTasks() {
    numTasks = 0;
}
void SchedulerImpl::scedule() {
    while (!timerFlag){}
    timerFlag = false;

    for(int i=0; i<numTasks; i++){
        if(taskArray[i]->updateAndCheckTime(period)){
            taskArray[i]->tick();
        }
    }
}