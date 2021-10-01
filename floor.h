#ifndef FLOOR_H
#define FLOOR_H
#include "problemset.h"

class Floor
{
public:
    Floor();
    ~Floor();
    Floor(ProblemSet *problem)          {this->p=problem;}
    void setProblem(ProblemSet *problem){this->p=problem;}
    ProblemSet *p;
private:
    int fn; //number of floor
};

#endif // FLOOR_H
