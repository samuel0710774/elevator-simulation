#include"Maxroot.h"

Maxroot::Maxroot(){}

string Maxroot::solve(string s)
{
    vector<double>v=stringtovectordouble(s);
    double *node=new double[15];

    for(int i=7;i<15;i++)
        node[i]=v[i];

    complete_tree(v,node);

    double max_value=node[0];
    int max_node=0;
    for(int i=1;i<15;i++)
    {
        if(max_value<node[i])
            max_value=node[i],max_node=i;
    }
    delete []node;
    stringstream a;
    string ans;
    a<<max_node+1<<":"<<fixed<<setprecision(3)<<max_value;

    return a.str();
}

void Maxroot::complete_tree(const vector<double> v, double *n)
{
    //layer 3
    for(int i=3;i<7;i++)
        n[i]=(n[2*i+1]+n[2*i+2])/2+v[i];
    //layer 2
    for(int i=1;i<3;i++)
        n[i]=(n[2*i+1]+n[2*i+2])/2+v[i];
    //layer 1
    n[0]=(n[1]+n[2])/2+v[0];
}
