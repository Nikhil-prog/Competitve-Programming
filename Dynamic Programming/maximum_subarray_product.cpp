/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
A subarray is a contiguous subsequence of the array.

Problem link: https://leetcode.com/problems/maximum-product-subarray/

*/

int maxProduct(vector<int> &nums)
{
    int prod1 = 1, prod2 = 1, max_prod = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp_prod1 = max({nums[i], nums[i] * prod1, nums[i] * prod2});
        int tmp_prod2 = min({nums[i], nums[i] * prod1, nums[i] * prod2});
        prod1 = tmp_prod1;
        prod2 = tmp_prod2;

        max_prod = max(max_prod, prod1);
    }
    return max_prod;
}

int main()
{
    vector<int> nums{2, 3, -2, 4};
    int max_product = maxProduct(nums);
    cout << "with sum as : " << max_product << "\n";
    return 0;
}