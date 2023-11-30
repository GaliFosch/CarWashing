#ifndef __PROXIMITY_TASK__
#define __PROXIMITY_TASK__

#include "SensorTask.hpp"
#include "components/api/ProximitySensor.hpp"

class ProximityTask : public SensorTask
{
private:
    ProximitySensor* pSensor;
    float minDist;
public:
    ProximityTask(unsigned int time, StateManager* sm, ProximitySensor* pSensor, float minDist);
    boolean isInState();
};


#endif