#include"longest_pair.h"
#include <float.h>
#include <stdlib.h>
#include <math.h>

Longest_Pair::Longest_Pair(){

}


double Longest_Pair::dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) +
                 (p1.z - p2.z)*(p1.z - p2.z)
               );
}


double Longest_Pair::min(double x, double y)
{
    return (x < y)? x : y;
}


double Longest_Pair::brutalWay(Point P[], int n)
{
    double max = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) > max){
                max = dist(P[i], P[j]);
            }
    return max;
}

double Longest_Pair::rounding(double num){
    num*=100;
    num = round(num);
    double ans = num/100;
    return ans;
}


string Longest_Pair::solve(string s)
{
    vector<double>v = stringtovectordouble(s);

    unsigned long long n =v.size();

    Point *P = new Point[n/3];
    for(unsigned long long i=0;i<n/3;i++){
        P[i].x = v[i*3];
        P[i].y = v[i*3+1];
        P[i].z = v[i*3+2];
    }

    //string ans = to_string(closest(P,n));
    string ans = to_string(rounding(brutalWay(P,n/3)));  //未完待續
    delete []P;
    ans.erase(ans.length()-4,4);
    return  ans;
}
/*1.00 1.00 1.00 1.05 1.00 1.00 3.05 4.87 5.78 3.87 4.12 8.24 7.19 100 9.57
99.56
0.00 0.00 0.00 3.00 4.00 0.00 6.01 7.08 8.08 4.87 5.32 9.87 15.897 19.57 20.48
32.48
1.16 2.0 8.87 11 12 13 25 26 27 13 14 15
38.38*/
