#include "myother.h"

MyOther::MyOther()
{

}
vector<int> MyOther::stringtoVectorInt(string s){
    string::size_type pos = 0, prev = 0;
    vector<int> i;

    while((pos = s.find_first_of(' ', pos)) != string::npos)
    {
        i.push_back(stoi(s.substr(prev, pos - prev)));
        prev = ++pos;
    }
    i.push_back(stoi(s.substr(prev)));

    return i;
};

string MyOther::vectorIntToString(vector<int> i){
    string s;

    s += to_string(i[0]);
    for(unsigned long long j = 1; j < i.size(); j++)
    {
        s += " " + to_string(i[j]);
    }

    return s;
};

vector<double> MyOther::stringtoVectorDouble(string s){
    string::size_type pos = 0, prev = 0;
    vector<double> i;

    while((pos = s.find_first_of(' ', pos)) != string::npos)
    {
        i.push_back(stod(s.substr(prev, pos - prev)));
        prev = ++pos;
    }
    i.push_back(stod(s.substr(prev)));

    return i;
};

string MyOther::vectorDoubleToString(vector<double> i){
    string s;

    s += to_string(i[0]);
    for(unsigned long long j = 1; j < i.size(); j++)
    {
        s += " " + to_string(i[j]);
    }

    return s;
};
vector<string> MyOther::stringtoVectorString_Mine(string s)
{
    string::size_type pos = 0, prev = 0;
    vector<string> i;

    while((pos = s.find_first_of(' ', pos)) != string::npos)
    {
        i.push_back((s.substr(prev, pos - prev)));
        prev = ++pos;
    }
    i.push_back((s.substr(prev)));

    return i;
}
string MyOther::vectorCharToString_Mine(vector<char> i)
{
     string res;
     for ( unsigned long long j = 0; j < i.size(); j++ )
     {
         res += i[j];
         if ( j != i.size() - 1 )
             res += " ";
         else
             break;
     }
     return res;
}
