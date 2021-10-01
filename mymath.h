#ifndef MYMATH_H
#define MYMATH_H
#include "problemset.h"
#include<sstream>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

class MyMath : public ProblemSet{
public:
    MyMath();
    virtual ~MyMath()=0;
    virtual string solve(string s)=0;
    vector<int>stringtovectorint(string);
    string vectorinttostring(vector<int>);
    vector<float>stringtovectorfloat(string);
    string vectorfloattostring(vector<float>);

    vector<double>stringtovectordouble(string);
    string vectordoubletostring(vector<double>);
};


#endif // MYMATH_H
