#ifndef __TASK__
#define __TASK__
#include <Arduino.h>
class Task
{
protected:
    unsigned int period;
    unsigned int timeCounter;
    boolean active;
public:
    virtual void init(unsigned int period)
    {
        this->period = period;
        Serial.println(this->period);
    }
    bool updateAndCheckTime(unsigned int time)
    {
        timeCounter += time;
        if (timeCounter >= period)
        {
            timeCounter = 0;
            return true;
        }
        return false;
    }
    virtual void tick() = 0;

    void activate(){
        active = true;
    }

    void deactivate(){
        active = false;
    }

    boolean isActive(){
        return active;
    }
};


#endif