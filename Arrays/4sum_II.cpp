/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given four integer arrays nums1, nums2, nums3, and nums4 all of length n,
    return the number of tuples (i, j, k, l) such that:

    0 <= i, j, k, l < n
    nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
    Time complexity required = O(n^2)

    Problem Link: https://leetcode.com/problems/4sum-ii/
*/

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{

    int n = nums1.size(), count = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[nums3[i] + nums4[j]]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[-(nums1[i] + nums2[j])] != 0)
                count += mp[-(nums1[i] + nums2[j])];
        }
    }
    return count;
}

int main()
{
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0, 2};
    cout << "Total tuples that have sum equal to zero are: " << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}