#ifndef MAZE_H
#define MAZE_H

#include "myother.h"
#include <QDebug>
#include <stack>

class Maze:public MyOther
{
public:
    Maze();
    ~Maze();
    string solve(string s);
    char **maze,**ans;
    bool **visited;
    string path;
    int M,N;
    int m,n;
    int fx,fy;

    bool isReachable(char ***,bool ***,int,int,char ***);
};

#endif // MAZE_H
