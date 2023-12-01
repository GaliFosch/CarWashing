#include "ProgressBarTask.hpp"

ProgressBarTask::ProgressBarTask(unsigned int time, StateManager *sm) : SensorTask(time, sm)
{
    this->init(100);
}

void ProgressBarTask::init(unsigned int period){
    this->SensorTask::init(period);
    maxCount = this->getTime()/period;
    counter = maxCount;
}

boolean ProgressBarTask::isInState(){
    compManager->print(String(counter));
    if(counter==0){
        counter = maxCount;
    }else{
        counter--;
    }
    return true;
}

void ProgressBarTask::exec(){
    sm->changeState();
}