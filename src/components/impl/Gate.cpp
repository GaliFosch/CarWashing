#include "../api/Gate.hpp"
#include <Arduino.h>

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 180

int delta = 1;

Gate::Gate(int pin) : servo(pin), pos(0)
{
    state = OPEN;
    pos = CLOSE_ANGLE;
    this->close();
}

Gate::~Gate()
{
    servo.~ServoMotorImpl();
}

void Gate::open()
{
    if (state == CLOSED)
    {
        servo.on();
        for (int i = pos; i > OPEN_ANGLE; i--)
        {
            servo.setPosition(pos);
            delay(5);
            pos += delta;
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
        for (int i = pos; i < CLOSE_ANGLE; i++)
        {
            servo.setPosition(pos);
            delay(5);
            pos -= delta;
        }
        servo.off();
        state = CLOSED;
    }
}