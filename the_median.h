#ifndef THE_MEDIAN_H
#define THE_MEDIAN_H

#include "mymath.h"
#include <QString>
#include <qsqldatabase.h>
#include <qsqlquery.h>

class The_Median:public MyMath
{
public:
    The_Median();
    ~The_Median();
    string solve(string s);
};

#endif // THE_MEDIAN_H
