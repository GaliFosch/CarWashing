#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

class TemperatureSensor
{
private:
    const int pin;

public:
    TemperatureSensor(int pin);
    ~TemperatureSensor();
    double read();
};

#endif