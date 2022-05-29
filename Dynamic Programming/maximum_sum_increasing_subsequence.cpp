/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.

*/

int max_sum_inc_subseq(vector<int> &nums)
{
    int n = nums.size();
    vector<int> msis(n, 1);
    for (int i = 0; i < n; i++)
    {
        msis[i] = nums[i];
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                msis[i] = max(msis[i], msis[j] + nums[i]);
            }
        }
    }
    return *max_element(msis.begin(), msis.end());
}

int main()
{
    vector<int> nums{1, 20, 4, 5, 6, 50};
    cout << "The maximum sum increasing subsequence of the given array is : " << max_sum_inc_subseq(nums) << "\n";
    return 0;
}