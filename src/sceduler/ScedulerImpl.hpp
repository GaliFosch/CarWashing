#ifndef __SCEDULER_IMPL__
#define __SCEDULER_IMPL__

#include "Sceduler.hpp"

#define MAX_TASKS 50

class ScedulerImpl : public Sceduler
{
private:
    Task* taskArray[MAX_TASKS];
    int numTasks;
    unsigned int period;
public:
    ScedulerImpl();
    ~ScedulerImpl();
    void init(unsigned int basePeriod);
    bool addTask(Task* task);
    void clearTasks();
    void scedule();
};

#endif