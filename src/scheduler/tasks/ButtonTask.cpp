#include "ButtonTask.hpp"

ButtonTask::ButtonTask(StateManager *sm, Button *button) : SensorTask(0, sm), b(button)
{
}

boolean ButtonTask::isInState(){
    return b->isPressed()>0;
}