#ifndef __FUNCTION_TASK__
#define __FUNCTION_TASK__

#include "Task.hpp"

class FunctionTask : public Task
{
private:
    void (*func)(void);
public:
    FunctionTask(void (*func)(void));
    ~FunctionTask();
    void init(unsigned int period);
    void tick();
};

#endif