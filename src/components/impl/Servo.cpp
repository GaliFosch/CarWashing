#include "../api/Servo.hpp"

#include "Arduino.h"

const float coeff = (2250.0-750.0)/180;

Servo::Servo(const int pin) : pin(pin)
{
}

Servo::~Servo()
{
}

void Servo::on(){
    motor.attach(pin);
}

void Servo::setPosition(int angle){
    motor.write(750 + angle * coeff);
}

void Servo::off(){
    motor.detach();
}