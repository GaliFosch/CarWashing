#include <Arduino.h>
#include "components/api/ServoMotorImpl.hpp"
#include "scheduler/Scheduler.hpp"
#include "scheduler/SchedulerImpl.hpp"
#include "scheduler/FunctionTask.hpp"
#include "PartManager.hpp"
#include "scheduler/BlinkTask.hpp"

Gate* g;
bool f = true;

void setup() {
  Serial.begin(9600);
  g = new Gate(5);
}

void loop() {
  if(f){
    g->open();
    f = false;
  }else{
    g->close();
    f = true;
  }
  delay(1000);
}