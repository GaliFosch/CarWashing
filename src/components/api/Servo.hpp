#ifndef __SERVO__
#define __SERVO__

class Servo
{
private:
    const int pin;
public:
    Servo(int pin);
    ~Servo();
    void pulseServo(int pulseLen);
};

#endif