#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.hpp"

#define MAX_TASKS 50

class Scheduler
{
public:
    virtual void init(unsigned int basePeriod) = 0;
    virtual bool addTask(Task* task) = 0;
    virtual void clearTasks() = 0;
    virtual void scedule() = 0;
};

#endif