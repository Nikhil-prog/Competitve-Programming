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

int edit_distance(string &s1, string &s2, int n, int m)
{
    vector<vector<int>> tab(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
        tab[i][0] = i;

    for (int j = 0; j <= m; j++)
        tab[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                tab[i][j] = tab[i - 1][j - 1];
            }
            else
            {
                tab[i][j] = 1 + min(tab[i - 1][j], min(tab[i][j - 1], tab[i - 1][j - 1]));
            }
        }
    }
    return tab[n][m];
}

int main()
{
    string s1 = "saturday";
    string s2 = "sunday";
    int n = s1.size();
    int m = s2.size();
    cout << "The minimum no. of operations required to change s1 to s2 are : " << edit_distance(s1, s2, n, m) << endl;
    return 0;
}