/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, return the longest palindromic substring in s.

Problem link: https://leetcode.com/problems/longest-palindromic-substring/
*/

string longestPalindrome(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case of length 1
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    // Base case of length 2
    for (int i = 0, j = 1; j < n; j++, i++)
    {
        if (s[i] == s[j])
        {
            dp[i][j] = 1;
            l = i;
            r = j;
        }
    }

    for (int k = 2; k < n; k++)
    {
        for (int i = 0, j = k; j < n; j++, i++)
        {
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                l = i;
                r = j;
            }
        }
    }
    return s.substr(l, r - l + 1);
}

int main()
{
    string s = "aaaabbaa";
    cout << "The longest palindromic substring: " << longestPalindrome(s) << endl;
    return 0;
}