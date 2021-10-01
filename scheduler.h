#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <iostream>

using namespace std;

class Scheduler
{
public:
    Scheduler();
    int getNowFloor();
    int getNowState();
    int getPassenger();
    unsigned long long getEnd(){ return end;}
    void updateEnd(){end++;}

    void updateIndex();
    unsigned long long getIndex(){return index;}

    //Push Now floor / state of elevator / number of passenger in elevator
    void push_nowFloor(int);
    void push_state(int);
    void push_passenger_num(int);

    unsigned long long get_nowFloor_vecSize(){ return nowFloor.size();}

    //Debug
    void nowFloor_List(){
        for(unsigned long long i=0;i<nowFloor.size();i++){
            cout<<"Now floor: "<<nowFloor[i]<<" || State: "<<state[i]<<" || people: "<< passenger_num[i]<<endl;
        }
    }

private:
    vector<int> nowFloor;
    vector<int> state;
    vector<int> passenger_num;
    unsigned long long index;
    unsigned long long end;//mark the end of the path
};

#endif // SCHEDULER_H
