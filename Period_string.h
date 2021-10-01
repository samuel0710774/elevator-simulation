#ifndef PERIOD_STRING_H
#define PERIOD_STRING_H
#include"mymath.h"
class Period_string:public MyMath
{
public:
    Period_string();
    string solve(string s);
    bool check(string S,string s);
};

#endif // PERIOD_STRING_H
