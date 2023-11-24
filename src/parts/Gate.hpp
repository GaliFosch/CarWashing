#ifndef __GATE__
#define __GATE__

#include "../components/api/Servo.hpp"


class Gate
{
private:
    Servo servo;
    enum{OPEN, CLOSED} state;
public:
    Gate(int pin);
    ~Gate();
    void open();
    void close();
};


#endif