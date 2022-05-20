/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

problem link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

int binary_search(vector<int> &res, int low, int high, int num)
{
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (res[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res{arr[0]};
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (res[len - 1] < arr[i])
        {
            res.push_back(arr[i]);
            len++;
        }
        else
        {
            int index = binary_search(res, 0, len - 1, arr[i]);
            res[index] = arr[i];
        }
    }
    return len;
}

int main()
{
    vector<int> arr{4, 10, 6, 5, 8, 11, 2, 20};
    cout << "The longest increasing subsequence of the given array is : " << lis(arr) << "\n";
    return 0;
}