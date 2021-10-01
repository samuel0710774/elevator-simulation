#ifndef LONGEST_PEEK_PALINDROME_H
#define LONGEST_PEEK_PALINDROME_H
#include "mystring.h"
#include <QDebug>

class Longest_Peek_Palindrome : public MyString
{
public:
    Longest_Peek_Palindrome();
    ~Longest_Peek_Palindrome(){}
    string solve(string);
};

#endif // LONGEST_PEEK_PALINDROME_H
