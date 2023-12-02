#include "ProximityTask.hpp"

ProximityTask::ProximityTask(unsigned int time, StateManager* sm, State state, ProximitySensor* pSensor, float dist, Mode mode) : 
    SensorTask(time,sm, state), 
    pSensor(pSensor), 
    dist(dist),
    mode(mode)
{
}

boolean ProximityTask::isInState()
{
    float read = pSensor->getDistance();
    if(read<0){
        return false;
    }
    if(mode==GREATER){
        return read >= dist;
    }else{
        return read <= dist;
    }
}