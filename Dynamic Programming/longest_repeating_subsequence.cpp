/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

int longest_rep_subseq(string &a)
{
    string b = a;
    int n = a.size(), m = b.size();
    vector<vector<int>> tab(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1] && i != j)
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
    string s = "AABEBCDD";
    cout << "The length of longest repeating subsequence: " << longest_rep_subseq(s) << endl;
    return 0;
}