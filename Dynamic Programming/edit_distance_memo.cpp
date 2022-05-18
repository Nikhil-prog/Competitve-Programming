/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Problem link: https://leetcode.com/problems/edit-distance/
*/

vector<vector<int>> memo;

int edit_distance(string &s1, string &s2, int n, int m)
{
    if (memo[n][m] == -1)
    {
        if (n == 0)
            memo[n][m] = m;
        else if (m == 0)
            memo[n][m] = n;
        else if (s1[n - 1] == s2[m - 1])
            memo[n][m] = edit_distance(s1, s2, n - 1, m - 1);
        else
            memo[n][m] = 1 + min(edit_distance(s1, s2, n, m - 1), min(edit_distance(s1, s2, n - 1, m), edit_distance(s1, s2, n - 1, m - 1)));
    }
    return memo[n][m];
}

int main()
{
    string s1 = "saturday";
    string s2 = "sunday";
    int n = s1.size();
    int m = s2.size();
    memo.resize(n + 1, vector<int>(m + 1, -1));
    cout << "The minimum no. of operations required to change s1 to s2 are : " << edit_distance(s1, s2, n, m) << endl;
    return 0;
}