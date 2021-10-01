#include "longest_peek_palindrome.h"

Longest_Peek_Palindrome::Longest_Peek_Palindrome()
{

}
string reverse(string s)
{
    string r = s;

    for(int i = 0; i < s.length(); i++)
        r[i] = s[s.length() - i - 1];

    return r;
}
string Longest_Peek_Palindrome::solve(string s)
{
    string sub;
    vector<string> ans;
    int ansIndex = 0;
    bool if_find = false;


    for(int i = 0; i < s.length(); i++)
    {
        if(ispunct(s[i]))
        {
            s.erase(s.begin() + i);
            i--;
        }
        else
            s[i] = toupper(s[i]);
    }

    for(int i = s.length(); i > 0; i--)
    {
        for(int j = 0; j <= s.length() - i; j++)
        {
            sub = s.substr(j, i);
            if(!sub.compare(reverse(sub)))
            {
                ans.push_back(sub);
                ansIndex++;
                if_find = true;
            }
        }
        if(if_find)
            break;
    }


    string finalans = ans[0];

    for(int i = 1; i < ans.size(); i++)
        if(finalans > ans[i])
            finalans = ans[i];

    return finalans;
}
