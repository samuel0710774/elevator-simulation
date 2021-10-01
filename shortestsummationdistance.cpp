#include "shortestsummationdistance.h"
#include <bits/stdc++.h>
ShortestSummationDistance::ShortestSummationDistance()
{

}
double dp[65536];
struct Node{
    double x,y;
};

Node node[20];

double ShortestSummationDistance::dist(int a,int b){
    double x=node[a].x-node[b].x;
    double y=node[a].y-node[b].y;
    return sqrt(x*x+y*y);
}
string ShortestSummationDistance::solve(string s){
    int n;
    stringstream ss;
    ss << s;
    string bx, by, ans;
    while(ss>>n){
        for(int i=0;i<2*n;i++){
            ss >>node[i].x>>node[i].y;
        }
        memset(dp,0,sizeof(dp));

        for(int s=1;s<(1<<n*2);s++){
            dp[s]=INT_MAX;
            int i;
            for(i=0;i<n*2;i++)
                if(s&(1<<i))
                    break;
            for(int j=i+1;j<n*2;j++)
                if(s&(1<<j))
                    dp[s]=min(dp[s],dist(i,j)+dp[s^(1<<i)^(1<<j)]);
        }

        stringstream strbuf;
        strbuf << fixed << setprecision(2) << dp[(1<<n*2)-1];
        ans += strbuf.str() + " ";
    }
    ans.erase(ans.length() - 1,1);
    return ans;
}
