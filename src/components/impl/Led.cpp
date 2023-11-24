#include "../api/led.hpp"

#include <Arduino.h>

Led::Led(const int pin) : pin(pin)
{
    pinMode(pin, OUTPUT);
    state = OFF;
}

Led::~Led()
{
}

void Led::turnOn()
{
    if (state == OFF)
    {
        digitalWrite(pin, HIGH);
        state = ON;
    }
}

void Led::turnOff()
{
    if (state == ON)
    {
        digitalWrite(pin, LOW);
        state = OFF;
    }
}

int Led::isOn()
{
    return state == ON;
}