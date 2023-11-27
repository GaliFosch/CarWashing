#include "BlinkTask.hpp"

#include <Arduino.h>

BlinkTask::BlinkTask(Led led): led(&led)
{
}

void BlinkTask::tick(){
    if(led->isOn()){
        led->turnOff();
    }else{
        led->turnOn();
    }
}