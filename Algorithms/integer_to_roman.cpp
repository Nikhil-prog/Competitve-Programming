/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given Integer in range 0 to 4999, return its
    conversion in Roman Number representation
*/

int search(int total, map<int, string> &mp)
{
    int res = 0;
    for (auto i : mp)
    {
        if (i.first <= total)
        {
            res = max(res, i.first);
        }
    }
    return res;
}

string intToRoman(int num)
{
    string res = "";
    vector<string> roman{"I", "V", "X", "L", "C", "D", "M", "IV", "IX", "XL", "XC", "CD", "CM"};
    vector<int> number{1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
    map<int, string> mp;
    for (int i = 0; i < number.size(); i++)
        mp[number[i]] = roman[i];

    while (num)
    {
        int x = search(num, mp);
        res += mp[x];
        num -= x;
    }
    return res;
}

int main()
{
    int arr[] = {1, 9, 19, 55, 105, 1964, 124, 4999, 515};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << "The Roman Number representation of " << arr[i] << " is : " << intToRoman(arr[i]) << endl;
    }
    return 0;
}