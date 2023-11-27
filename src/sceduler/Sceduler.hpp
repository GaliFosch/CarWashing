#ifndef __SCEDULER__
#define __SCEDULER__

#include "Task.hpp"

#define MAX_TASKS 50

class Sceduler
{
public:
    Sceduler();
    ~Sceduler();
    virtual void init(unsigned int basePeriod);
    virtual bool addTask(Task* task);
    virtual void clearTasks();
    virtual void scedule();
};

#endif