#include"Mario.h"
Mario::Mario()
{

}

string Mario::solve(string s)
{
    vector<int>v=stringtovectorint(s);
    int n=v[0];
    v.erase(v.begin());
/*  int index,sum;
    for(int i=v.size()-1;i>=0;i--)
    {
        index=i,sum=0;
        while(sum<v[i] && index>0)
        {
            index--;
            sum+=v[index];
        }
        if(sum>=v[i])
            v.erase(v.begin()+index);
    }*/
    int sum=v[0];
    int ans=2;
    for (int i = 1; i < n - 1; i++)
    {
        if (sum < v[i] && sum+v[i] < v[i + 1])
        {
            sum += v[i];
            ans++;
        }
    }

    return to_string(ans);
}
