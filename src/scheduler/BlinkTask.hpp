#ifndef __BLINK_TASK__
#define __BLINK_TASK__

#include "scheduler/Task.hpp"
#include "components/api/Led.hpp"

class BlinkTask: Task
{
private:
    Led* led;
public:
    BlinkTask(Led* led);
    void tick();
};

#endif