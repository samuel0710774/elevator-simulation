#ifndef PROBLEMSET_H
#define PROBLEMSET_H
#include<iostream>
#include<string.h>
#include<iomanip>
#include<sstream>
#include<math.h>
#include <vector>
#include <limits>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;
class ProblemSet
{
public:
    ProblemSet();
    virtual string solve(string s)=0;
    virtual ~ProblemSet()=0;
};

#endif // PROBLEMSET_H
