#include"Period_string.h"
Period_string::Period_string()
{

}

string Period_string::solve(string s)
{
    string r;
    for(int i=0;i<s.length();i++)
    {
        r+=s[i];
        if(check(s,r))
            break;
    }
    return to_string(r.length());
}

bool Period_string::check(string S,string s)
{
    if(S.length()%s.length()!=0)
        return false;
    unsigned long long left=0;
    //string ss;
    for(int i=1;i<=S.length()/s.length();i++)
    {
        if(s!=S.substr(left,s.length()))
            return 0;
        left+=s.length();
    }
    return 1;
}
