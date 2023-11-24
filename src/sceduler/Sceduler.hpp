#ifndef __SCEDULER__
#define __SCEDULER__

#include "Task.hpp"

#define MAX_TASKS 50

class Sceduler
{
private:
    Task* taskArray[MAX_TASKS];
    int numTasks;
    unsigned int period;
public:
    Sceduler(/* args */);
    ~Sceduler();
    void init(unsigned int basePeriod);
    bool addTask(Task* task);
    void clearTasks();
    void scedule();
};

#endif