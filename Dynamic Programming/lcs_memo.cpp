/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int lcs(string &a, string &b, int n, int m)
{
    if (memo[n][m] == -1)
    {
        if (n == 0 || m == 0)
            memo[n][m] = 0;
        else if (a[n - 1] == b[m - 1])
            memo[n][m] = 1 + lcs(a, b, n - 1, m - 1);
        else
            memo[n][m] = max(lcs(a, b, n - 1, m), lcs(a, b, n, m - 1));
    }
    return memo[n][m];
}

int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int n = x.size(), m = y.size();
    memo.resize(n + 1, vector<int>(m + 1, -1));
    cout << "The length of longest common subsequence: " << lcs(x, y) << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}