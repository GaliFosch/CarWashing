#include "ButtonTask.hpp"

ButtonTask::ButtonTask(StateManager *sm, Button *button, State state) : SensorTask(0, sm, state), b(button)
{
}

boolean ButtonTask::isInState(){
    return b->isPressed()>0;
}