#include "../api/Button.hpp"

Button::Button(int pin) : pin(pin)
{
    pinMode(pin, INPUT);
}

Button::~Button()
{
}

boolean Button::isPressed()
{
    return digitalRead(pin) == HIGH;
}
