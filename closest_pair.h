#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H

#include "mymath.h"

class Closest_Pair:public MyMath
{
public:
    struct Point{
        float x,y,z;
    };

    Closest_Pair();

    float dist(Point , Point );

    float min(float , float );
    float max(float , float );

    float stripClosest(Point strip[], int size, float d);


    float brutalWay_short(Point [], int);
    float brutalWay_long(Point [], int);

    float closestUtil(Point [],Point [],int);
    int compareX(const void *,const void *);
    int compareY(const void *,const void *);

    float closest(Point [],int);
    float rounding(float);

    string solve(string s);
};


#endif // CLOSEST_PAIR_H
