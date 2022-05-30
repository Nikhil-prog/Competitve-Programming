/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Problem link: https://leetcode.com/problems/maximum-subarray/

*/

// Kadane's algorithm
int maxSubArray(vector<int> &nums)
{
    // msf - maxsum so far, meh - max end here,
    // start = start index of answer subarray
    // end  = ending index of answer subarray
    // s = temporary start index, if  upcoming subarray becomes new answer

    int msf = nums[0], meh = 0, start = 0, end = 0, s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        meh += nums[i];
        if (meh > msf)
        {
            msf = meh;
            start = s;
            end = i;
        }

        if (meh < 0)
        {
            meh = 0;
            s = i + 1;
        }
    }

    // printing the final answer subarray (remove if not required)
    cout << "The maximum sum subarray is : \n";
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return msf;
}

int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSubArray(nums);
    cout << "with sum as : " << max_sum << "\n";
    return 0;
}