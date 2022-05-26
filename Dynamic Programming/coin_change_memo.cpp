/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Problem link: https://leetcode.com/problems/coin-change/submissions/
*/

vector<int> memo;
vector<bool> visited;

int coinChange(vector<int> &coins, int amount)
{
    if (!visited[amount])
    {
        visited[amount] = true;
        for (int i = 0; i < coins.size(); i++)
        {
            if (amount - coins[i] >= 0)
            {
                int subcase = coinChange(coins, amount - coins[i]);
                if (subcase != INT_MAX)
                {
                    memo[amount] = min(memo[amount], subcase + 1);
                }
            }
        }
    }
    return memo[amount];
}

int main()
{
    // Example 1
    vector<int> coins1{1, 2, 5};
    int amount1 = 11;
    memo.resize(amount1 + 1, INT_MAX);
    visited.resize(amount1 + 1, false);
    memo[0] = 0;
    visited[0] = true;
    int change1 = coinChange(coins1, amount1);
    cout << "The fewest number of coins required to make amount : " << ((change1 == INT_MAX) ? -1 : change1) << "\n";

    // resetting global vectors
    memo.clear();
    visited.clear();

    // Example 2
    vector<int> coins2{2};
    int amount2 = 3;
    memo.resize(amount2 + 1, INT_MAX);
    visited.resize(amount2 + 1, false);
    memo[0] = 0;
    visited[0] = true;
    int change2 = coinChange(coins2, amount2);
    cout << "The fewest number of coins required to make amount : " << ((change2 == INT_MAX) ? -1 : change2) << "\n";
    return 0;
}