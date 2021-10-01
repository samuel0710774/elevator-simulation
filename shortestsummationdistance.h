#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H
#include "mymath.h"

class ShortestSummationDistance : public MyMath
{
public:
    ShortestSummationDistance();
    ~ShortestSummationDistance(){}
    double dist(int a,int b);
    string solve(string);
};

#endif // SHORTESTSUMMATIONDISTANCE_H
