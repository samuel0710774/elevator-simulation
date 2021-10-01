#ifndef DATABASE1_H
#define DATABASE1_H
#include "mymath.h"
#include <QString>

class Database1:public MyMath
{
public:
    Database1();
    vector<QString> vs;
    QString order;
    string solve(string);
    inline void step7();
    inline void step8();
    inline void step9();

};

#endif // DATABASE1_H
