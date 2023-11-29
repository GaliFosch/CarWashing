#ifndef __GATE__
#define __GATE__

#include "ServoMotorImpl.hpp"

class Gate
{
private:
    ServoMotorImpl servo;
    int pos;
    enum
    {
        OPEN,
        CLOSED
    } state;

public:
    Gate(int pin);
    ~Gate();
    void open();
    void close();
};

#endif