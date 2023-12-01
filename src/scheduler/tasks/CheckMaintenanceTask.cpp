#include "CheckMaintenanceTask.hpp"

CheckMaintenanceTask::CheckMaintenanceTask(StateManager *sm) : SensorTask(0,sm)
{
}

boolean CheckMaintenanceTask::isInState(){
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "ok"){
            delete msg;
            return true;
        }
        delete msg;
    }
    return false;
}