/*Nikhil*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mostFrequentElement(int *arr, int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    int maxfreq = -1;
    int mostFreqElement = -1;
    for (auto x : freq)
    {
        if (x.second > maxfreq)
        {
            maxfreq = x.second;
            mostFreqElement = x.first;
        }
    }

    return mostFreqElement;
    //return maxfreq;   //for maximum frequency
}

int main()
{
    int arr[] = {1, 1, 2, 3, 5, 1, 3, 1};
    cout << mostFrequentElement(arr, 8) << endl;
    return 0;
}