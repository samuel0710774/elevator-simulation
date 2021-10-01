#include "add1.h"

//--------------------------------------Add1 class-----------------------------//

Add1::Add1()
{

}

string Add1::solve(string s)
{
    vector<int>v=stringtovectorint(s);

    for(unsigned int i=0;i<v.size();i++)
        v[i]++;
    return vectorinttostring(v);
}
