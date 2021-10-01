#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H
#include "mystring.h"
#include <QDebug>

class Longest_Common_Substring : public MyString
{
public:
    Longest_Common_Substring();
    ~Longest_Common_Substring(){}
    string solve(string);
};

#endif // LONGEST_COMMON_SUBSTRING_H
