#ifndef DATABASE6_H
#define DATABASE6_H
#include "mymath.h"

class Database6:public MyMath
{
public:
    Database6();
    vector<QString> vs;
    void step14();
    void step15();
    void step16();
    void Load_Data();
    vector<QString>StringToVectorQString(string);
    QString order;
    string solve(string);
};

#endif // DATABASE6_H
