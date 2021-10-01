#ifndef FIBONACCI_H
#define FIBONACCI_H
#include"mymath.h"

class Fibonacci:public MyMath{
public:
    Fibonacci();
    ~Fibonacci();
    int fib(int);
    string solve(string);
    int fib_series[60];
    int fib_series_original[60];
};

#endif // FIBONACCI_H
