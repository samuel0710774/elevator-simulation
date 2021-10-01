#ifndef MYTREE_H
#define MYTREE_H
#include "problemset.h"

class MyTree : public ProblemSet
{
public:
    MyTree();
    ~MyTree(){}
    virtual string solve(string) = 0;
    vector<double> stringtoVectorDouble(string);
    string vectorDoubleToString(vector<double>);
    struct node
    {
        struct node *left; //left child node
        struct node *right; //right child node
        string keyStr;
        int keyInt;
    };
};

#endif // MYTREE_H
