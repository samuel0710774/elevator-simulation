#include "fibonacci.h"

Fibonacci::Fibonacci(){
    fib_series[0] = 0;
    fib_series[1] = 1;
    fib_series_original[0] = 0;
    fib_series_original[1] = 1;

    for(int i=2;i<60;i++){
        fib_series_original[i] = (fib_series_original[i-1]+fib_series_original[i-2])%60;
    }


    for(int i=2;i<60;i++)
        fib_series[i]=(fib_series[i-1]+fib_series[i-2])%10;
}

Fibonacci::~Fibonacci(){

}

int Fibonacci::fib(int n)
{
    return fib_series[n];
}

string Fibonacci::solve(string s)
{
    vector<int>v=stringtovectorint(s);
    vector<int>ans;
    long long temp;
    for(unsigned int i=0;i<v.size();i++)
    {
        temp = fib_series_original[v[i]%60];
        ans.push_back(fib(temp%60));
    }
    return vectorinttostring(ans);
}
