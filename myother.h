#ifndef MYOTHER_H
#define MYOTHER_H
#include "problemset.h"

class MyOther : public ProblemSet
{
public:
    MyOther();
    ~MyOther(){}
    virtual string solve(string) = 0;
    vector<int> stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
    vector<double> stringtoVectorDouble(string);
    string vectorDoubleToString(vector<double>);
    vector<string> stringtoVectorString_Mine(string);
    string vectorCharToString_Mine(vector<char>);
};

#endif // MYOTHER_H
