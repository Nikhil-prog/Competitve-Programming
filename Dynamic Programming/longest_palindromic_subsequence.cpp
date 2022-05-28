/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Problem link: https://leetcode.com/problems/longest-palindromic-subsequence/
*/

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

int longestPalindromeSubseq(string &s)
{
    string b = s;
    reverse(b.begin(), b.end());
    return lcs(s, b);
}

int main()
{
    string s = "cbbd";
    cout << "The length of longest palindromic subsequence: " << longestPalindromeSubseq(s) << endl;
    return 0;
}