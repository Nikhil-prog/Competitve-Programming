/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                tab[i][j] = tab[i - 1][j - 1] + 1;
            }
            else
            {
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
            }
        }
    }
    return tab[n][m];
}

int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    cout << "The length of longest common subsequence: " << lcs(x, y) << endl;
    return 0;
}