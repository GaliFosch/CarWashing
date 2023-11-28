#ifndef __BLINK_TASK__
#define __BLINK_TASK__

#include "scheduler/Task.hpp"
#include "components/api/Led.hpp"

class BlinkTask: public Task
{
private:
    Led* led;
public:
    BlinkTask(Led led);
    void tick();
    void init(unsigned int period);
};

#endif