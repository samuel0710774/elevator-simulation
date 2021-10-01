#include "large_factorial.h"


Large_Factorial::Large_Factorial()
{

}

string Large_Factorial::solve(string s){
    vector<int>v = stringtovectorint(s);
    string ans;
    int res[MAX];

       // Initialize result
       res[0] = 1;
       int res_size = 1;

       // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
       for (int x=2; x<=v[0]; x++)
           res_size = multiply(x, res, res_size);

       for (int i=res_size-1; i>=0; i--)
           ans+=to_string(res[i]);
       return ans;
}

int Large_Factorial::multiply(int x, int res[], int res_size){
    int carry = 0;  // Initialize carry

        // One by one multiply n with individual digits of res[]
        for (int i=0; i<res_size; i++)
        {
            int prod = res[i] * x + carry;

            // Store last digit of 'prod' in res[]
            res[i] = prod % 10;

            // Put rest in carry
            carry  = prod/10;
        }

        // Put carry in res and increase result size
        while (carry)
        {
            res[res_size] = carry%10;
            carry = carry/10;
            res_size++;
        }
        return res_size;
}

void Large_Factorial::factoril(int){

}
