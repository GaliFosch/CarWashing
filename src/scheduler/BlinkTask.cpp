#include "BlinkTask.hpp"

#include <Arduino.h>

BlinkTask::BlinkTask(Led led): led(&led)
{
}

void BlinkTask::init(unsigned int period){
  Task::init(period);
}

void BlinkTask::tick(){
    if(led->isOn()){
        led->turnOff();
    }else{
        led->turnOn();
    }
}