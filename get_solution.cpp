#include "get_solution.h"

Get_Solution::Get_Solution()
{

}
string Get_Solution::solve(string s)
{
    vector<double> data = stringtovectordouble(s);

        int count = 0;
        int N = data[count];
        count++;

        double **A;
        A = new double* [N];
        for(int i = 0; i < N; i++)
            A[i] = new double [N];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                A[i][j] = data[count];
                count++;
            }
        }

        double *b;
        b = new double[N];
        for(int i = 0; i < N; i++)
        {
            b[i] = data[count];
            count++;
        }

        double *t1;
        t1 = new double[N];
        double t2;
        for(int i = 0; i < N; i++)
            if(A[i][i] == 0)
                for(int j = i + 1; j < N; j++)
                    if(A[j][i] != 0)
                    {
                        for(int k = 0; k < N; k ++)
                        {
                            t1[k] = A[i][k];
                            A[i][k] = A[j][k];
                            A[j][k] = t1[k];
                        }
                        t2 = b[i];
                        b[i] = b[j];
                        b[j] = t2;
                    }

        double *c;
        c = new double[N];
        for (int k = 0; k < N - 1; k++)
        {
            for (int i = k + 1; i < N; i++)
                c[i] = A[i][k] / A[k][k];
            for (int i = k + 1; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    A[i][j] = A[i][j] - c[i] * A[k][j];
                b[i] = b[i] - c[i] * b[k];
            }
        }

        double *x;
        x = new double[N];
        x[N - 1] = b[N - 1] / A[N - 1][N - 1];

        for (int i = N - 2; i >= 0; i--)
        {
            double sum = 0;
            for (int j = i + 1; j < N; j++)
                sum += A[i][j] * x[j];
            x[i] = (b[i] - sum) / A[i][i];
        }

        stringstream tmp;
        string ans;
        for (int i = 0; i < N; i++)
        {
            tmp.clear();
            tmp << fixed << setprecision(2) << x[i];
            string tmpans;
            tmp >> tmpans;
            if ( i == N - 1 )
                ans += tmpans;
            else
                ans += tmpans + " ";
            tmp.str("");
        }

        for(int i = 0; i < N; i++)
            delete [] A[i];
        delete [] A;
        delete [] b;
        delete [] c;
        delete [] x;
        delete [] t1;

        return ans;
}

