#include "FunctionTask.hpp"

FunctionTask::FunctionTask(void (*func)(void)): func(func){}

FunctionTask::~FunctionTask(){}

void FunctionTask::init(unsigned int period){
    this->period = period;
}

void FunctionTask::tick(){
    func();
}