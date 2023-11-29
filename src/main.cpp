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
  Serial.begin(9600);
  s->init(1000);
}

void loop() {
  s->scedule();
  Serial.println(sm->getState());
}