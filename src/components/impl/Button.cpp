#include "../api/Button.hpp"

#include <Arduino.h>

Button::Button(int pin):pin(pin)
{
    pinMode(pin, INPUT);
}

Button::~Button()
{
}

int Button::isPressed()
{
    return digitalRead(pin)==HIGH;
}
