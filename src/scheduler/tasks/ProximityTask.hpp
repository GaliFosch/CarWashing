#ifndef __PROXIMITY_TASK__
#define __PROXIMITY_TASK__

#include "SensorTask.hpp"
#include "components/api/ProximitySensor.hpp"


class ProximityTask : public SensorTask
{
private:
    ProximitySensor* pSensor;
    float dist;
public:
    typedef enum{GREATER, LOWER} Mode;
    ProximityTask(unsigned int time, StateManager* sm, State state, ProximitySensor* pSensor, float dist, Mode mode);
    boolean isInState();
private:
    Mode mode;
};


#endif