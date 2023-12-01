#ifndef __PROGRESS_BAR_TASK__
#define __PROGRESS_BAR_TASK__

#include "SensorTask.hpp"

class ProgressBarTask : public SensorTask
{
private:
    unsigned int maxCount;
    unsigned int counter;
    void init(unsigned int period);
public:
    ProgressBarTask(unsigned int time, StateManager* sm);
    boolean isInState();
    void exec();
};


#endif