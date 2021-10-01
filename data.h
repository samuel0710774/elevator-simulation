#ifndef DATA_H
#define DATA_H

#include<QString>
#include <iostream>

using namespace std;

class Data
{
public:
    Data();
    qint64 spendtime;
    string testdata;
    string submit;
    string answer; //for double check
    bool correct;
    int score;
    int nowfloor;
    int nowState;
    int nowPassenger;
    int distance;
    int pre_floor;
};

#endif // DATA_H
