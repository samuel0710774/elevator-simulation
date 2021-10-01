#ifndef PRIME_H
#define PRIME_H
#include "problemset.h"
#include "mymath.h"

class Prime:public MyMath{
public:
    Prime();
    string solve(string s);
    int primemax(int q,vector<int>pt);
    void update_table(int q,vector<int>&pt);
};
#endif // PRIME_H
