/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Problem link: https://leetcode.com/problems/missing-number/
*/

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int x : nums)
    {
        sum += x;
    }
    return (n * (n + 1)) / 2 - sum;
}

int main()
{
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing number is: " << missingNumber(nums) << "\n";
    return 0;
}