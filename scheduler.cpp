#include "scheduler.h"

Scheduler::Scheduler()
{
    index = 0;
    end=0;
}

int Scheduler::getNowFloor(){

    return nowFloor[index];
}

int Scheduler::getNowState(){
    return  state[index];
}

int Scheduler::getPassenger(){
    return passenger_num[index];
}

void Scheduler::updateIndex(){
    index++;
}

void Scheduler::push_nowFloor(int floor){
    nowFloor.push_back(floor);
}

void Scheduler::push_passenger_num(int number){
    passenger_num.push_back(number);
}

void Scheduler::push_state(int In_Out){
    state.push_back(In_Out);
}
