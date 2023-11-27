#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

class PIRSensor
{
private:
    int pin;

public:
    PIRSensor(int pin);
    ~PIRSensor();
    int read();
};

#endif