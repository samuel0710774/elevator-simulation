#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
    int destination;
    int Number;  //Number of people who arewaiting
    int arrNum;  //number of people to be arrive
public:
    People();
    void setDestination(int d){destination = d;}
    void setNumber(int num){Number = num;}
    void setArrNum(int num){arrNum = num;}
    int getDestination(){return  destination;}
    int getNumber(){return Number;}
    int getArrNum(){return arrNum;}
};

#endif // PEOPLE_H
