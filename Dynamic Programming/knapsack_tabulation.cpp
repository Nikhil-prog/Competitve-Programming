/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or dont pick it (0-1 property).

Problem link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

int knapSack(vector<int> &val, vector<int> &wt, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j - wt[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> val{1, 2, 3};
    vector<int> wt{4, 5, 1};
    int W = 4;
    int n = 3;
    cout << "Maximum acheivable value is : " << knapSack(val, wt, W, n) << "\n";
    return 0;
}