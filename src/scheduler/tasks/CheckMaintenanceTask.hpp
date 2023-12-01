#ifndef __CHECK_MAINTENANCE_TASK__
#define __CHECK_MAINTENANCE_TASK__

#include "SensorTask.hpp"
#include "serial/MsgService.hpp"

class CheckMaintenanceTask : public SensorTask
{
public:
    CheckMaintenanceTask(StateManager* sm);
    boolean isInState();
};
#endif