#include "closet_pair.h"
#include <cmath>
#include <sstream>
#include <iomanip>
Closet_Pair::Closet_Pair()
{

}

Closet_Pair::~Closet_Pair(){

}

string Closet_Pair::solve(string s){
    vector<double> d;
    stringstream sout;
    double dis, small = 9999999999;

    d = stringtoVectorDouble(s);

    for(size_t i = 0; i<d.size()/3 - 1; i++){
        for(size_t j = i + 1; j<d.size()/3; j++){
            dis = (d[3 * i] - d[3 * j]) * (d[3 * i] - d[3 * j]) + (d[3 * i + 1] - d[3 * j + 1]) * (d[3 * i + 1] - d[3 * j + 1]) + (d[3 * i + 2] - d[3 * j + 2]) * (d[3 * i + 2] - d[3 * j + 2]);
            if(dis<small)
                small = dis;
        }
    }
    sout<<fixed<<setprecision(2)<<sqrt(small);
    return sout.str();
}
