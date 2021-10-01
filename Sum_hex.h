#ifndef SUM_HEX_H
#define SUM_HEX_H
#include"mymath.h"
class Sum_hex:public MyMath
{
public:
    Sum_hex();
    string solve(string s);
    int hex_to_dec(char);
    char dec_to_hex(int n);
};

#endif // SUM_HEX_H
