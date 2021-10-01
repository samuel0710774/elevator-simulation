#include"Get_signature.h"
Get_signature::Get_signature(){}

string Get_signature::solve(string s)
{
    vector<int>v=stringtovectorint(s);
    int n=v[0];
    v.erase(v.begin());
    vector<int>order;
	int index;
	
    //list
    for(int i=0;i<n;i++)
    {
        index=0;
        while(v[index] != i+1)
            index+=2;
        order.push_back(v[index+1]-1);
        v.erase(v.begin()+index);
        v.erase(v.begin()+index);
    }

    /*if no one pass to him,he must get maximum*/

    //max signature
    int max=0;
    //which professor
    int number;
	int c;
    bool *f=new bool[n];
    for(int i=0;i<n;i++)
        f[i]=false;
    //find max signature
    for(int i=0;i<n;i++)
    {
        c=0,index=i;
        do
        {
            f[index]=true;
            c++;
            index=order[index];
            //cout<< i<<index<<endl;
            if(f[index])
                break;
        }while(c<n && index!=i);
        
        if(c>max)
            number=i,max=c;
        if(max==n)
            break;
        for(int i=0;i<n;i++)
            f[i]=false;
    }
    return to_string(number+1);
}
