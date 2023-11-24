#ifndef __SERVO__
#define __SERVO__

#include <ServoTimer2.h>

class Servo
{
private:
    int pin;
    ServoTimer2 motor;
public:
    Servo(int pin);
    ~Servo();
    void on();
    void setPosition(int angle);
    void off();
};

#endif