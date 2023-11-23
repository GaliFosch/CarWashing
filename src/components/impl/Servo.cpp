#include "../api/Servo.hpp"

#include "Arduino.h"

Servo::Servo(const int pin): pin(pin){
    pinMode(pin, OUTPUT);
}

Servo::~Servo(){

}

void Servo::pulseServo(const int pulseLen){
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseLen);
    digitalWrite(pin,LOW);
    delay(15);
}