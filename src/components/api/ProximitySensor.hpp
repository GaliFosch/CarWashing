#ifndef __PROXIMITY_SENSOR__
#define __PROXIMITY_SENSOR__

class ProximitySensor
{
private:
    const int trigPin;
    const int echoPin;
    float vs;
public:
    ProximitySensor(int trigPin, int echoPin, int temperature);
    ~ProximitySensor();
    float getDistance();
    void setTemperature(float temperature);
};

#endif
