#include"shy_game.h"

Shy_game::Shy_game(){

}

void Shy_game::Givenum(int *a[],int remain,int p,int start)
{
    int i=1;

    if(start>p)
        start=0;

    if(remain==p)
    {
        for(int k=0;k<remain;k++)
            *a[k]=k+1;
    }

    else
    {
        while (i!=remain)
        {
             if(*a[start]==0)
                 start++;
             else
             {
                 *a[start++]=i;
                 i++;
             }
        }
    }

}

int Shy_game::eliminate(int *a[],int n,int p)
{
    for(int i=0;i<p;i++)
        if(*a[i]==n)
        {*a[i]=0;return i;}

}

int Shy_game::finalperson(int a[],int p)
{
    for(int i=0;i<p;i++)
        if(a[i])
            return i;
}

string Shy_game::solve(string s)
{
    vector<int>v=stringtovectorint(s);
    vector<int>ans;

    int p=v[0];
    v.erase(v.begin());

    vector<int>number;
    int e,index;
    for(unsigned int i=0;i<v.size();i++)
    {
        index=0;
        for(int j=0;j<p;j++)
            number.push_back(j+1);

        while(number.size()!=1)
        {
            e=v[i]%number.size()-1;
            if(e<0)
                e=number.size()-1;
            index+=e;
            if(index>=number.size())
                index-=number.size();
            number.erase(number.begin()+index);
            if(index>=number.size())
                index=0;
        }
        ans.push_back(number[0]);
        number.pop_back();
    }

    return vectorinttostring(ans);
}
