#ifndef SHYGAME_H
#define SHYGAME_H

#include "mymath.h"

class Shy_game:public MyMath{
public:
    Shy_game();
    string solve(string s);
    void Givenum(int *a[],int remain,int p,int start);
    int finalperson(int a[],int p);
    int eliminate(int *a[],int n,int p);
};

#endif // SHYGAME_H
