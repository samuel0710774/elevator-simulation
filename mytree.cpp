#include "mytree.h"

MyTree::MyTree()
{

}
vector<double> MyTree::stringtoVectorDouble(string s){
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

string MyTree::vectorDoubleToString(vector<double> i){
    string s;

    s += to_string(i[0]);
    for(unsigned long long j = 1; j < i.size(); j++)
    {
        s += " " + to_string(i[j]);
    }

    return s;
};
