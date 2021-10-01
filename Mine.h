#ifndef MINE_H
#define MINE_H
#include"mymath.h"


class Mine:public MyMath
{
public:
    Mine();
    ~Mine();
    string solve(string s);
    void plus(vector<vector<char> >&,int,int ,int ,int );
};

#endif // MINE_H
