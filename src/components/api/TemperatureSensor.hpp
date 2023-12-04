#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

class TemperatureSensor
{
private:
    uint8_t pin;

public:
    TemperatureSensor(uint8_t pin);
    ~TemperatureSensor();
    double read();
};

#endif