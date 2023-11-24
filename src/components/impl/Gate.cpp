#include "../api/Gate.hpp"

#define OPEN_ANGLE 90
#define CLOSE_ANGLE 0

Gate::Gate(int pin): servo(pin){

}

Gate::~Gate(){
    servo.~Servo();
}

void Gate::open(){
    if(state==CLOSED){
        servo.on();
        servo.setPosition(OPEN_ANGLE);
        servo.off();
        state = OPEN;
    }
}

void Gate::close(){
    if(state==OPEN){
        servo.on();
        servo.setPosition(CLOSE_ANGLE);
        servo.off();
        state = CLOSED;
    }
}