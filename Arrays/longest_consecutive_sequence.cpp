/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Problem link: https://leetcode.com/problems/longest-consecutive-sequence/

*/
int start = -1;

int longestConsecutive(vector<int> &nums)
{
    int ans = 0;
    unordered_set<int> allnum;
    // or use unordered_map<int, int> allnum
    // with allnum[nums[i]] = 1, if element is present

    for (int x : nums)
    {
        allnum.insert(x);
    }

    for (int x : nums)
    {
        if (allnum.count(x - 1) == 0)
        {
            int len = 1;
            int num = x + 1;
            while (allnum.count(num))
            {
                len++;
                num++;
            }

            if (len > ans)
            {
                ans = len;
                start = x;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{100, 4, 200, 1, 3, 2};
    int longest_seq = longestConsecutive(nums);
    cout << "The longest Consecutive sequence has length : " << longest_seq << "\n";
    cout << ">> ";
    for (int i = start; i < start + longest_seq; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}