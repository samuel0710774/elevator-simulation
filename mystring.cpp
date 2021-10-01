#include "mystring.h"

MyString::MyString()
{

}
MyString::~MyString(){

}
vector<string> MyString::stringToVectorstring(string s)
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
