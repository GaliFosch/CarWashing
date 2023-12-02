#ifndef __TEMPERATURE_TASK__
#define __TEMPERATURE_TASK__

#include "SensorTask.hpp"
#include "components/api/TemperatureSensor.hpp"


class TemperatureTask : public SensorTask
{
private:
    TemperatureSensor* tS;
    double temp;
public:
    typedef enum{GREATER, LOWER} Mode;
    TemperatureTask(unsigned int time, StateManager* sm, State state, TemperatureSensor* tS, double temperature, Mode mode);
    boolean isInState();
    void exec();
private:
    Mode mode;
};


#endif