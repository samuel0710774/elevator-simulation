#ifndef FACTORIAL_H
#define FACTORIAL_H
#include "mymath.h"
#include<cmath>

class Factorial:public MyMath
{
public:
    Factorial();
    ~Factorial();
    string solve(string s);
    int Build(int MAX, int input);
    string FindANS(int MAX, int input);

};

#endif // FACTORIAL_H

