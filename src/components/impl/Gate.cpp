#include "../api/Gate.hpp"
#include <Arduino.h>

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 200

int delta = 1;

Gate::Gate(int pin) : servo(pin)
{
    state = OPEN;
}

Gate::~Gate()
{
    servo.~ServoMotorImpl();
}

void Gate::init(){
    servo.on();
    for(int i = 0; i<CLOSE_ANGLE;i++){
        servo.setPosition(i);
        delay(5);
    }
    state = CLOSED;
    servo.off();
}

void Gate::open()
{
    if (state == CLOSED)
    {
        servo.on();
        for (int i = CLOSE_ANGLE; i > OPEN_ANGLE; i--)
        {
            servo.setPosition(i);
            delay(5);
        }
        servo.off();
        state = OPEN;
    }
}

void Gate::close()
{
    if (state == OPEN)
    {
        servo.on();
        for (int i = OPEN_ANGLE; i < CLOSE_ANGLE; i++)
        {
            servo.setPosition(i);
            delay(5);
        }
        servo.off();
        state = CLOSED;
    }
}