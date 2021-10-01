#include"Sum_hex.h"

Sum_hex::Sum_hex(){

}

string Sum_hex::solve(string s)
{
    stringstream ss;
    string add,ans;
    vector<int>r;
    int index;
    ss<<s;
    ss>>add;
    for(int i=0;i<add.length();i++)
        r.push_back(hex_to_dec(add[i]));

    //add
    while(ss>>add)
    {
        if(add=="0")
            break;
        index=r.size()-1;
        for(int i=add.length()-1;i>=0;i--)
        {
            if(index<0)
                r.insert(r.begin(),hex_to_dec(add[i]));
            else
            {
                r[index]+=hex_to_dec(add[i]);
                index--;
            }
        }
    }
    //to hex
    int c=0;
    for(int i=r.size()-1;i>=0;i--)
    {
        r[i]+=c;
        c=0;
        if(r[i]>15)
        {
            c=r[i]/16;
            r[i]=r[i]%16;
        }
        ans=dec_to_hex(r[i])+ans;
    }
    while(c!=0)
    {
        ans=dec_to_hex(c%16)+ans;
        c/=16;
    }
    return ans;
}

int Sum_hex::hex_to_dec(char c)
{
    switch (c)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        case '0':
            return 0;

    }
}

char Sum_hex::dec_to_hex(int n)
{
    switch (n)
    {
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        case 10:
            return 'a';
        case 11:
            return 'b';
        case 12:
            return 'c';
        case 13:
            return 'd';
        case 14:
            return 'e';
        case 15:
            return 'f';
        case 0:
            return '0';

    }
}
