#include "../api/Gate.hpp"
#include <Arduino.h>

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 0

Gate::Gate(int pin): servo(pin){
    state = CLOSED;
}

Gate::~Gate(){
    servo.~ServoMotorImpl();
}

void Gate::open(){
    if(state==CLOSED){
        Serial.println("open");
        servo.on();
        servo.setPosition(OPEN_ANGLE);
        servo.off();
        state = OPEN;
    }
}

void Gate::close(){
    if(state==OPEN){
        Serial.println("closed");
        servo.on();
        servo.setPosition(CLOSE_ANGLE);
        servo.off();
        state = CLOSED;
    }
}