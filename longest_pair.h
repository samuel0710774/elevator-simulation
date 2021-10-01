#ifndef LONGEST_PAIR_H
#define LONGEST_PAIR_H

#include"mymath.h"

class Longest_Pair:public MyMath{
public:
    struct Point{
        double x,y,z;
    };

    Longest_Pair();
    double dist(Point , Point );

    double min(double , double );

    double brutalWay(Point [], int);

    double rounding(double);

    string solve(string s);

};

#endif // LONGEST_PAIR_H
