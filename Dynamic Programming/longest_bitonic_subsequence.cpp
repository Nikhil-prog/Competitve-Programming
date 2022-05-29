/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.

*/

// longest increasing subsequence
vector<int> lis(vector<int> &nums, int n)
{
    vector<int> res(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    return res;
}

// longest decreasing subsequence
vector<int> lds(vector<int> &nums, int n)
{
    vector<int> res(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i])
            {
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    return res;
}

int bitonic(vector<int> &nums)
{
    int n = nums.size();
    vector<int> a = lis(nums, n);
    vector<int> b = lds(nums, n);

    // OR instead of createing and calling lds do this:
    // reverse(nums.begin(), nums.end());
    // vector<int> b = lis(nums, n);
    // reverse(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1 && b[i] != 1) // remove this if-condition if increasing or decreasing part can be empty
        {
            res = max(res, a[i] + b[i] - 1);
        }
    }
    return res;
}

int main()
{
    vector<int> nums{1, 11, 2, 10, 4, 5, 2, 1};
    cout << "The longest bitonic subsequence of the given array is : " << bitonic(nums) << "\n";
    return 0;
}