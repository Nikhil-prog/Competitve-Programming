/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

problem link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
*/

int maximizeTheCuts(int n, int a, int b, int c)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);
        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);

        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n] == -1 ? 0 : dp[n];
}
int main()
{
    // Subcase #1
    int n1 = 4, x1 = 2, y1 = 1, z1 = 1;
    cout << "The maximum cuts for subcase #1 : " << maximizeTheCuts(n1, x1, y1, z1) << "\n";

    // subcase #2
    int n2 = 23, x2 = 11, y2 = 12, z2 = 13;
    cout << "The maximum cuts for subcase #1 : " << maximizeTheCuts(n2, x2, y2, z2) << "\n";

    // subcase #3
    int n3 = 3, x3 = 2, y3 = 4, z3 = 5;
    cout << "The maximum cuts for subcase #1 : " << maximizeTheCuts(n3, x3, y3, z3) << "\n";
    return 0;
}