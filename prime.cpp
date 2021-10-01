#include "prime.h"

//------------------------------------Primee class---------------------------------//


Prime::Prime()
{

}
int Prime::primemax(int q,vector<int>pt)
{
    bool f;
    for(int i=q;q>=2;i--)
    {
        f=true;
        for(unsigned int j=0;j<pt.size();j++)
        {
            if(i%pt[j]==0)
            {
                f=false;
                break;
            }
        }
        if(!f)
            continue;
        else
            return i;
    }
    return 0;
}

void Prime::update_table(int q,vector<int>&pt)
{
    int a=pt[pt.size()-1]+2,b=int(sqrt(q))+1;
    int index;
    bool *f=new bool[b-a+1];

    for(int i=0;i<b-a+1;i++)
            f[i]=true;

    for(unsigned int i=0;i<pt.size();i++)
    {
        if(a%pt[i]==0){index=0;}
        else {index=pt[i]-(a%pt[i]);}
        for(int j=index;j<b-a+1;j++)
            f[j]=false;
    }

    for(int i=0;i<b-a+1;i++)
        if(f[i]=true)                       //I don't understand??
            pt.push_back(a+i);
}

string Prime::solve(string s)
{
    vector<int>primetable={2,3,5,7,11,13,17,19};
    vector<int>ans;
    vector<int>ques=stringtovectorint(s);
    for(unsigned int i=0;i<ques.size();i++)
    {
        if(((ques[i]&1)==0) && (ques[i]!=2))
            ques[i]--;
        if(primetable[primetable.size()-1]<int(sqrt(ques[i]))+1)
            update_table(ques[i],primetable);
        ans.push_back(primemax(ques[i],primetable));
    }
    return vectorinttostring(ans);
}

