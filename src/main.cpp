#include <Arduino.h>
#include "StateManager.hpp"

StateManager* sManager;

void setup()
{
    sManager = new StateManager();

    sManager->init();
}

void loop()
{
    sManager->step();
}