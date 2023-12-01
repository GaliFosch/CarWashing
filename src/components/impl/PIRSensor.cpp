#include "../api/PIRSensor.hpp"

#include <Arduino.h>

PIRSensor::PIRSensor(int pin) : pin(pin)
{
    pinMode(pin, INPUT);
}

PIRSensor::~PIRSensor()
{
}

int PIRSensor::read()
{
    return digitalRead(pin);
}

int PIRSensor::getPin(){
    return pin;
}