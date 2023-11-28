#include <Arduino.h>

#include "scheduler/Scheduler.hpp"
#include "scheduler/SchedulerImpl.hpp"
#include "StateManager.hpp"

Scheduler* s;
StateManager* sm;

void setup() {
  s = new SchedulerImpl();
  sm = new StateManager(State::SLEEP, s);
  PartManager::getInstance()->init();
  sm->changeState(State::ENETERING);
  s->init(50);
}

void loop() {
  s->scedule();
}