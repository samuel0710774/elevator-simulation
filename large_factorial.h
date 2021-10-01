#ifndef LARGE_FACTORIAL_H
#define LARGE_FACTORIAL_H

#include "mymath.h"

#define MAX 20000

class Large_Factorial:public MyMath
{
public:
    Large_Factorial();
    string solve(string s);
    int multiply(int,int [],int);
    void factoril(int);
};

#endif // LARGE_FACTORIAL_H
