#include"Mine.h"

Mine::Mine(){

}

Mine::~Mine(){

}

string Mine::solve(string s)
{
    int row=0,col=0,i;
    stringstream ss;
    vector<vector<char>>ans;

    ss<<s;
    //find row,col
    for(i=0;i<2;i++)
    {

        if(i==0){
            ss>>row;
        }else
            ss>>col;
    }

    while(s[i]!='.' && s[i]!='*')
        i++;

    for(int r=0;r<row;r++)
    {
        vector<char>a;
        for(int c=0;c<col;c++)
        {
            if(s[i]=='*')
                a.push_back('*');
            else
                a.push_back('0');
            i++;
        }
        i++;
        ans.push_back(a);
    }
    //finish map
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++)
        {
            if(ans[r][c]=='*')
            {
                plus(ans,r-1,c-1,row,col);
                plus(ans,r-1,c,row,col);
                plus(ans,r-1,c+1,row,col);
                plus(ans,r,c-1,row,col);
                plus(ans,r,c+1,row,col);
                plus(ans,r+1,c-1,row,col);
                plus(ans,r+1,c,row,col);
                plus(ans,r+1,c+1,row,col);
            }
        }
    }
    //outpt ans string
    string answer;
    for(int r=0;r<row;r++)
    {
        for(int c=0;c<col;c++){
            answer+=ans[r][c];
        }
        if(r!=row-1){
            answer+=' ';
        }
    }
    //answer.pop_back();
    //answer.substr(0,answer.length()-1);
    //answer.erase(answer.length()-1,1);
    return answer;
}

void Mine::plus(vector<vector<char> >&ans,int r,int c,int row,int col)
{
    if(r<0 || c<0 || r>=row || c>=col)
        return;
    if(ans[r][c]!='*'){
            ans[r][c]++;
    }
}
