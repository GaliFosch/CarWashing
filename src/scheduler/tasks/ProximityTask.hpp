#ifndef __PROXIMITY_TASK__
#define __PROXIMITY_TASK__

#include "SensorTask.hpp"
#include "components/api/ProximitySensor.hpp"

typedef enum{GREATER, LOWER} Mode;

class ProximityTask : public SensorTask
{
private:
    ProximitySensor* pSensor;
    float dist;
    Mode mode;
public:
    ProximityTask(unsigned int time, StateManager* sm, ProximitySensor* pSensor, float dist, Mode mode);
    boolean isInState();
};


#endif