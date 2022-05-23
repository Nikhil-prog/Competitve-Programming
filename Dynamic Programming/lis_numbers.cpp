/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

problem link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

int lis_num(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lis(n);
    vector<int> freq(n);
    lis[0] = 1;
    freq[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        freq[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (lis[i] <= lis[j] + 1)
                {
                    if (lis[i] == lis[j] + 1)
                    {
                        freq[i] += freq[j];
                    }
                    else
                    {
                        lis[i] = lis[j] + 1;
                        freq[i] = freq[j];
                    }
                }
            }
        }
    }

    int mx = *max_element(lis.begin(), lis.end());
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (lis[i] == mx)
        {
            res += freq[i];
        }
    }
    return res;
}

int main()
{
    vector<int> nums{1, 2, 4, 3, 5, 4, 7, 2};
    cout << "The Numbers of longest increasing subsequence of the given array is : " << lis_num(nums) << "\n";
    return 0;
}