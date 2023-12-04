#include "ProgressBarTask.hpp"

ProgressBarTask::ProgressBarTask(unsigned int time, StateManager *sm, State state) : SensorTask(0, sm, state)
{
    this->SensorTask::init(1000);
    maxCount = time/1000;
    counter = maxCount;
}

boolean ProgressBarTask::isInState(){
    compManager->print(String(counter));
    if(counter==0){
        counter = maxCount;
        return true;
    }else{
        counter--;
    }
    return false;
}