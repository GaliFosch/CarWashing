#include "../api/TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(uint8_t pin) : pin(pin)
{
}
TemperatureSensor::~TemperatureSensor()
{
}
double TemperatureSensor::read()
{
    int value = analogRead(pin);
    int value_in_mV = 4.8876 * value;
    return value_in_mV * 0.1;
}