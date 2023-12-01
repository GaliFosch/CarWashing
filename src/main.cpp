#include <Arduino.h>
#include "StateManager.hpp"
#include "serial/MsgService.hpp"

StateManager* sManager;

void setup()
{
    sManager = new StateManager();

    MsgService.init();
    sManager->init();
}

void loop()
{
    sManager->step();
}