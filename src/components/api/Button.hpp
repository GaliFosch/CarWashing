#ifndef __BUTTON__
#define __BUTTON__

#include <Arduino.h>

class Button
{
private:
    int pin;

public:
    Button(int pin);
    ~Button();
    boolean isPressed();
};

#endif