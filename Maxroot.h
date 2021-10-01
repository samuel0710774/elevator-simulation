#ifndef MAXROOT_H
#define MAXROOT_H
#include"mymath.h"
class Maxroot:public MyMath
{
public:
    Maxroot();
    string solve(string s);
    void complete_tree(const vector<double>v,double n[]);
};

#endif // MAXROOT_H
