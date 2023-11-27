#include <Arduino.h>
#include "scheduler/Scheduler.hpp"
#include "scheduler/SchedulerImpl.hpp"
#include "scheduler/BlinkTask.hpp"

#include "PartManager.hpp"

Scheduler* s;

void setup()
{
  s = new SchedulerImpl();
  s->init(50);
  BlinkTask* b = new BlinkTask(PartManager::getInstance().getLed1());
  b->init(100);
  s->addTask(b);
  Serial.begin(9600);
}

void loop()
{
  s->scedule();
}