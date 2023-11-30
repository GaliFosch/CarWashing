#include "ProximityTask.hpp"

ProximityTask::ProximityTask(unsigned int time, StateManager* sm, ProximitySensor* pSensor, float minDist) : 
    SensorTask(time,sm), 
    pSensor(pSensor), 
    minDist(minDist)
{
}

boolean ProximityTask::isInState(){
    return pSensor->getDistance()<=minDist;
}