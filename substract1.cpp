#include "substract1.h"

Substract1::Substract1()
{

}

string Substract1::solve(string s)
{
    vector<int>v=stringtovectorint(s);

    for(unsigned int i=0;i<v.size();i++)
        v[i]--;
    return vectorinttostring(v);
}
