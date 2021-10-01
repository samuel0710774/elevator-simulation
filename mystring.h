#ifndef MYSTRING_H
#define MYSTRING_H
#include "problemset.h"

class MyString : public ProblemSet
{
public:
    MyString();
    virtual string solve(string s) = 0;
    virtual ~MyString()=0;
    vector<string> stringToVectorstring(string s);
};

#endif // MYSTRING_H
