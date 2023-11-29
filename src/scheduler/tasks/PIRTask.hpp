#ifndef __PIR_TASK__
#define __PIR_TASK__

#include "components/api/PIRSensor.hpp"
#include "SensorTask.hpp"

class PIRTask : public SensorTask
{
private:
    PIRSensor* pir;
public:
    PIRTask(unsigned int time, PIRSensor* pir, StateManager* sm);
    boolean isInState();
};


#endif