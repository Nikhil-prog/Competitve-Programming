#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
using matrix = vector<vector<int>>;

matrix matrix_multiply(matrix a, matrix b)
{
    int x = a.size(), y = a[0].size(), z = b[0].size();
    matrix c(x, vector<int>(z));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < z; j++)
        {
            int value = 0;
            for (int k = 0; k < y; k++)
            {
                value += a[i][k] * b[k][j];
                // to avoid integer/long overflow
                value %= mod;
            }
            c[i][j] = value;
        }
    }
    return c;
}

matrix matrix_power(matrix a, int n)
{
    int m = a.size();
    matrix I(m, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        I[i][i] = 1;
    }

    if (n == 0)
    {
        return I;
    }
    else if (n == 1)
    {
        return a;
    }
    matrix h = matrix_power(a, n / 2);
    if (n % 2)
    {
        return matrix_multiply(matrix_multiply(h, h), a);
    }
    else
    {
        return matrix_multiply(h, h);
    }
}

int fast_fibonaaci(int n)
{
    if (n <= 1)
        return n;
    matrix base{{1}, {1}, {0}};
    matrix coeffcient{
        {1, 1, 0},
        {1, 0, 0},
        {0, 1, 0}};
    matrix p = matrix_power(coeffcient, n - 2);
    base = matrix_multiply(p, base);
    return base[0][0];
}

int32_t main()
{
    for (int i = 0; i < 51; i++)
    {
        cout << "The " << i << " term of fibonacci is : " << fast_fibonaaci(i) << endl;
    }
    return 0;
}