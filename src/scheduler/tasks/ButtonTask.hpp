#ifndef __BUTTON_TASK__
#define __BUTTON_TASK__

#include "SensorTask.hpp"
#include "components/api/Button.hpp"

class ButtonTask : public SensorTask
{
private:
    Button* b;
public:
    ButtonTask(StateManager* sm, Button* button, State state);
    boolean isInState();
};


#endif