#include "../api/ProximitySensor.hpp"

#include <Arduino.h>

ProximitySensor::ProximitySensor(int trigPin, int echoPin, int temperature) : trigPin(trigPin), echoPin(echoPin)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    setTemperature(temperature);
}

ProximitySensor::~ProximitySensor()
{
}

float ProximitySensor::getDistance()
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    float tUS = pulseIn(echoPin, HIGH);
    if(tUS<0){
        return -1;
    }
    float t = tUS / 1000.0 / 1000.0 / 2;
    float d = t * vs;
    return d;
}

void ProximitySensor::setTemperature(const float temperature)
{
    vs = 331.5 + 0.6 * temperature;
}