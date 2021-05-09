/*Nikhil*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//counts frequency of all elements in an array
void countFrequency(int *arr, int size)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    //printing frequency of all element
    for (auto x : freq)
    {
        cout << x.first << " " << x.second << "\n";
    }
}

int main()
{
    int arr[] = {1, 1, 2, 3, 5, 1, 3, 1};
    countFrequency(arr, 8);
    return 0;
}