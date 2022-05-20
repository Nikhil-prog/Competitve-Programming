/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

problem link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; i++)
    {
        res[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    return *max_element(res.begin(), res.end());
}

int main()
{
    vector<int> arr{4, 10, 6, 5, 8, 11, 2, 20};
    cout << "The longest increasing subsequence of the given array is : " << lis(arr) << "\n";
    return 0;
}