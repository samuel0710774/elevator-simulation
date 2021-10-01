#include "longest_common_substring.h"

Longest_Common_Substring::Longest_Common_Substring()
{

}
string Longest_Common_Substring::solve(string s)
{
    vector<string> data = stringToVectorstring(s);

    string s1 = data[0], s2 = data[1], t;

    for(int i = 0; i < s1.length(); i++)
    {
        if(ispunct(s1[i]))
        {
            s1.erase(s1.begin() + i);
            i--;
        }
        else
            s1[i] = toupper(s1[i]);
    }
    for(int i = 0; i < s2.length(); i++)
    {
        if(ispunct(s2[i]))
        {
            s2.erase(s2.begin() + i);
            i--;
        }
        else
            s2[i] = toupper(s2[i]);
    }
    if(s1.length() > s2.length())
    {
        t = s1;
        s1 = s2;
        s2 = t;
    }

    string sub1, sub2;
    vector<string> ans;
    int ansIndex = 0;
    bool if_find = false;

    for(int i = s1.length(); i > 0; i--)
    {
        for(int j = 0; j <= s1.length() - i; j++)
        {
            sub1 = s1.substr(j, i);
            for(int k = 0; k <= s2.length() - i; k++)
            {
                sub2 = s2.substr(k, i);
                if(!sub1.compare(sub2))
                {
                    ans.push_back(sub1);
                    ansIndex++;
                    if_find = true;
                }
            }
        }
        if(if_find)
            break;
    }

    string finalans = ans[0];

    for(int i = 1; i < ans.size(); i++)
        if(finalans > ans[i])
            finalans = ans[i];

    //qDebug() << "3." << finalans.c_str();
    return finalans;
}
