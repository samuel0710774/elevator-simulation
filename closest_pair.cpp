#include "closest_pair.h"
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <QDebug>

Closest_Pair::Closest_Pair()
{

}

struct Point{
    float x,y,z;
};

float Closest_Pair::dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) +
                 (p1.z - p2.z)*(p1.z - p2.z)
               );
}


float Closest_Pair::min(float x, float y)
{

    return (x < y)? x : y;
}
float Closest_Pair::max(float x, float y)
{
    return (x > y)? x : y;
}

float Closest_Pair::stripClosest(Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d

    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float Closest_Pair::brutalWay_short(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
float Closest_Pair::brutalWay_long(Point P[], int n)
{
    int i,j;
    double max = 0;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) > max)
                max = dist(P[i], P[j]);
    return max;
}

float Closest_Pair::closestUtil(Point Px[],Point Py[],int n){
    if(n<=3)
        return brutalWay_short(Px,n);

    int mid = n/2;
    Point midPoint = Px[mid];

    Point Pyl[mid+1];     //Left half
    Point Pyr[n-mid-1];   //Right half

    int li=0;
    int ri=0;
    for(int i=0;i<n;i++){
        if(Py[i].x<=midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    float dl = closestUtil(Px,Pyl,mid);
    float dr = closestUtil(Px + mid,Pyr,n-mid);

    float d = min(dl,dr);

    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(Py[i].x - midPoint.x)<d)
            strip[j] = Py[i],j++;
    }

    return  min(d,stripClosest(strip,j,d));

}

int Closest_Pair::compareX(const void *a,const void *b){
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int Closest_Pair::compareY(const void *a,const void *b){
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float Closest_Pair::closest(Point P[],int n){
    Point Px[n];
    Point Py[n];
    for(int i=0;i<n;i++){
        Px[i] = P[i];
        Py[i] = P[i];
    }

    //qsort(Px,n,sizeof(Point),compareX);
    //qsort(Px,n,sizeof(Point),compareY);

    return  closestUtil(Px,Py,n);
}

float Closest_Pair::rounding(float num){
    num*=100;
    num = round(num);
    return num/=100;
}

string Closest_Pair::solve(string s){
    vector<float>v = stringtovectorfloat(s);
    vector<float>ans;

    //cout<<s<<endl;
    int n = v.size();

    Point *P = new Point[n/3];
    for(int i=0;i<n/3;i++){
        P[i].x = v[i*3];
        P[i].y = v[i*3+1];
        P[i].z = v[i*3+2];
    }

    //string ans = to_string(closest(P,n));
    ans.push_back(brutalWay_short(P,n/3));
    ans.push_back(brutalWay_long(P,n/3));


    //cout<<ans[1]<<endl;
    //string ans = to_string(rounding(brutalWay(P,n/3)));  //未完待續
    delete []P;

    return  vectorfloattostring(ans);
}

