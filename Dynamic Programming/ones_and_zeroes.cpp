/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

problem link: https://leetcode.com/problems/ones-and-zeroes/
*/

int dp(vector<pair<int, int>> &freq, int m, int n, int l)
{
    vector<vector<vector<int>>> tab(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= l; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (j - freq[i - 1].first >= 0 && k - freq[i - 1].second >= 0)
                {
                    tab[i][j][k] = max(tab[i - 1][j - freq[i - 1].first][k - freq[i - 1].second] + 1, tab[i - 1][j][k]);
                }
                else
                {
                    tab[i][j][k] = tab[i - 1][j][k];
                }
            }
        }
    }
    return tab[l][m][n];
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    int size = strs.size();
    vector<pair<int, int>> freq;
    for (string s : strs)
    {
        int zeroes = 0;
        for (char i : s)
        {
            if (i == '0')
            {
                zeroes++;
            }
        }
        freq.push_back({zeroes, s.size() - zeroes});
    }
    return dp(freq, m, n, freq.size());
}

int main()
{
    int m = 5, n = 3;
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    cout << "The largest possible subset is : " << findMaxForm(strs, m, n) << "\n";
    return 0;
}