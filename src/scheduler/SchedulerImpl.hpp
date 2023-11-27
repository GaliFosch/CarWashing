#ifndef __SCHEDULER_IMPL__
#define __SCHEDULER_IMPL__

#include "Scheduler.hpp"

#define MAX_TASKS 50

class SchedulerImpl : public Scheduler
{
private:
    Task *taskArray[MAX_TASKS];
    int numTasks;
    unsigned int period;

public:
    SchedulerImpl();
    ~SchedulerImpl();
    void init(unsigned int basePeriod);
    bool addTask(Task *task);
    void clearTasks();
    void scedule();
};

#endif