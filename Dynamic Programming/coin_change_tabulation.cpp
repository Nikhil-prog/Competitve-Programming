/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Problem link: https://leetcode.com/problems/coin-change/submissions/
*/

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main()
{
    // Example 1
    vector<int> coins1{1, 2, 5};
    int amount1 = 11;
    cout << "The fewest number of coins required to make amount : " << coinChange(coins1, amount1) << "\n";

    // Example 2
    vector<int> coins2{2};
    int amount2 = 3;
    cout << "The fewest number of coins required to make amount : " << coinChange(coins2, amount2) << "\n";
    return 0;
}