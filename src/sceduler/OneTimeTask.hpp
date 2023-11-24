#ifndef __ONE_TIME_TASK__
#define __ONE_TIME_TASK__

#include "Task.hpp"
template <typename T>
class OneTimeTask : public Task
{
private:
    void (*func)(T);
public:
    OneTimeTask();
    void tick();
    void setFunction(void (*func)(T));
};
#endif
