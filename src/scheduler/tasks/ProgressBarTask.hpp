#ifndef __PROGRESS_BAR_TASK__
#define __PROGRESS_BAR_TASK__

#include "SensorTask.hpp"
#include "components/ComponentsManager.hpp"

class ProgressBarTask : public SensorTask
{
private:
    ComponentsManager* compManager = ComponentsManager::getInstance();
    unsigned int maxCount;
    unsigned int counter;
    void init(unsigned int period);
public:
    ProgressBarTask(unsigned int time, StateManager* sm, State state);
    boolean isInState();
};


#endif