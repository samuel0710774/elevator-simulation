#include "factorial.h"


const int N = 50000;
int Fac[N];


Factorial::Factorial()
{

}

Factorial::~Factorial(){

}

int Factorial::Build(int MAX, int input) {
    while (Fac[MAX] < input) {
        MAX++;
        Fac[MAX] = Fac[MAX - 1];

        int temp = MAX, Range = pow(MAX, 0.5);
        for (int i = 2; i <= Range; i++) {

            if (temp%i==0) {
                temp /= i;
                Fac[MAX] = Fac[MAX] + 1 + Fac[temp] - Fac[temp - 1];
                break;
            }

        }
        if (temp == MAX) Fac[MAX]++;

    }
    return MAX;
}

string Factorial::FindANS(int MAX, int input) {
    string ans;
    int i = 2, tf = 1;
    while (Fac[i] < input) {
        i++;
        if (Fac[i] == input) { tf = 1; break; }
        tf = 0;
    }

    if (tf){
        ans+=to_string(i);
        ans+="! ";
    }else{
        ans+="N ";
    }

    return ans;
}

string Factorial::solve(string s){
    vector<int>v=stringtovectorint(s);

    string ans;
    int MAX_Fact=2;
    Fac[0] = 0;
    Fac[1] = 0;
    Fac[2] = 1;
    for(int i=0;i<v.size();i++){
        if (v[i] > Fac[MAX_Fact]) MAX_Fact = Build(MAX_Fact, v[i]);
        ans+=FindANS(MAX_Fact, v[i]);
    }

    ans.erase(ans.length()-1,1);
    return ans;
}

