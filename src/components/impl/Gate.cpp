#include "../api/Gate.hpp"
#include <Arduino.h>

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 0

int delta = 1;

Gate::Gate(int pin): servo(pin), pos(0){
    state = CLOSED;
}

Gate::~Gate(){
    servo.~ServoMotorImpl();
}

void Gate::open(){
    if(state==CLOSED){
        Serial.println("open");
        servo.on();
        for (int i = 0; i < 90; i++) {
            Serial.println(pos);
            servo.setPosition(pos);          
            pos += delta;
        }
        servo.off();
        state = OPEN;
    }
}

void Gate::close(){
    if(state==OPEN){
        Serial.println("closed");
        servo.on();
        for (int i = 0; i < 90; i++) {
            Serial.println(pos);
            servo.setPosition(pos);          
            pos -= delta;
        }
        servo.off();
        state = CLOSED;
    }
}