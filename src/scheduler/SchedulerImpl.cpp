#include "SchedulerImpl.hpp"

#include <TimerOne.h>
#include "PartManager.hpp"

volatile bool timerFlag;

void timerHandler(void)
{
    timerFlag = true;
}

SchedulerImpl::SchedulerImpl():numTasks(0)
{
}

SchedulerImpl::~SchedulerImpl() {}

void SchedulerImpl::init(unsigned int basePeriod)
{
    this->period = basePeriod;
    long period = 1000l*basePeriod;
    Timer1.initialize(period);
    Timer1.attachInterrupt(timerHandler);
    timerFlag=true;
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