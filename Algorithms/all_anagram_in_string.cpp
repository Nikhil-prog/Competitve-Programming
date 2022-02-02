/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given two strings s and p, return an array
    of all the start indices of p's anagrams in s

    Problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

bool isAnagram(vector<int> &freq)
{
    for (int i : freq)
        if (i != 0)
            return false;
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<int> res, freq(26, 0);
    for (char c : p)
        freq[c - 'a']++;

    for (int i = 0; i < m && i < n; i++)
        freq[s[i] - 'a']--;

    if (isAnagram(freq))
        res.push_back(0);

    for (int i = m; i < n; i++)
    {
        freq[s[i - m] - 'a']++;
        freq[s[i] - 'a']--;
        if (isAnagram(freq))
            res.push_back(i - m + 1);
    }
    return res;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> ans = findAnagrams(s, p);
    cout << "All starting index of substring of string s, that are Anagram of string p: ";
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}