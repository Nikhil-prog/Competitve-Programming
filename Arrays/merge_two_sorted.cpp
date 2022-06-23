/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;
/*
Problem statement:
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/

// The following function is implementation of GAP METHOD
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    for (int gap = (n + m + 1) / 2;; gap = (gap + 1) / 2)
    {
        int i = 0;
        int j = i + gap;
        while (j < n + m)
        {
            if (i < n && j < n)
            {
                if (arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
            }
            else if (i < n)
            {
                if (arr1[i] > arr2[j - n])
                    swap(arr1[i], arr2[j - n]);
            }
            else
            {
                if (arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);
            }
            i++;
            j++;
        }

        if (gap == 1)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr1{1, 3, 5, 7};
    vector<int> arr2{0, 2, 6, 8, 9};
    merge(arr1, arr2, arr1.size(), arr2.size());
    cout << "ARR1 : ";
    for (int x : arr1)
        cout << x << " ";
    cout << "\nARR2 : ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;
    return 0;
}