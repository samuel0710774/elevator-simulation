#include "mymath.h"

MyMath::MyMath()
{

}

MyMath::~MyMath(){

}

string MyMath::vectorinttostring(vector<int> v)
{

    string s="";
    for(unsigned long long i=0;i<v.size();i++)
    {
        s+=to_string(v[i]);
        s+=" ";
    }
    s.erase(s.length()-1,1);
    return s;
}


vector<int> MyMath::stringtovectorint(string s)
{
    vector<int>v;
    int n;
    stringstream ss;
    ss<<s;
    while(ss>>n)
    {
        v.push_back(n);
    }
    return v;
}


string MyMath::vectorfloattostring(vector<float> v)
{
    std::ostringstream ss;
    //stringstream ss;
    string ans;
    for(int i=0;i<v.size();i++){       
        ss<<fixed<<setprecision(2)<<v[i]<<" ";
    }
    /*while (ss>>ans) {
        cout<<"Ans: "<<ans<<endl;
    }*/

    //ss>>ans;


    ans = ss.str().substr(0, ss.str().length() - 1);

    ans.substr(0,ans.length()-1);
    //cout<<ans<<endl;
    return ans;
}


vector<float> MyMath::stringtovectorfloat(string s)
{
    vector<float>v;
    float n;
    stringstream ss;
    ss<<s;
    while(ss>>n)
    {
        v.push_back(n);
    }
    return v;
}

string MyMath::vectordoubletostring(vector<double> v)
{
    stringstream ss;
    string ans;
    for(int i=0;i<v.size();i++){
        ss<<fixed<<setprecision(2)<<v[i];
    }
    ss>>ans;
    return ans;
}


vector<double> MyMath::stringtovectordouble(string s)
{
    vector<double>v;
    double n;
    stringstream ss;
    ss<<s;
    while(ss>>n)
    {
        v.push_back(n);
    }
    return v;
}







