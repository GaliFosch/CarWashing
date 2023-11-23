#include "../api/led.hpp"

#include <Arduino.h>

Led::Led(const int pin): pin(pin){
    pinMode(pin, OUTPUT);
    state = OFF;
}

Led::~Led(){

}

Led::turnOn(){
    if(state == OFF){
        digitalWrite(pin, HIGH);
        state = ON;
    }
}

Led::turnOFF(){
    if(state == ON){
        digitalWrite(pin, LOW);
        state = OFF;
    }
}

Led::isOn(){
    return state == ON;
}