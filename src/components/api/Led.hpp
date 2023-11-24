#ifndef __LED__
#define __LED__

class Led
{
private:
    const int pin;
    enum
    {
        ON,
        OFF
    } state;

public:
    Led(int pin);
    ~Led();
    void turnOn();
    void turnOff();
    int isOn();
};

#endif