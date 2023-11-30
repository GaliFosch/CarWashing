#ifndef __TEMPERATURE_TASK__
#define __TEMPERATURE_TASK__

#include "SensorTask.hpp"
#include "components/api/TemperatureSensor.hpp"

typedef enum{GREATER, LOWER} Mode;

class TemperatureTask : public SensorTask
{
private:
    TemperatureSensor* tS;
    double temp;
    Mode mode;
public:
    TemperatureTask(unsigned int time, StateManager* sm, TemperatureSensor* tS, double temperature, Mode mode);
    boolean isInState();
};


#endif