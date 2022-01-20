/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

// merging two sorted array In-place
void merge(int *arr, int l, int mid, int r)
{
    // sizes of left and right subarray to be merge
    int n = mid - l + 1, m = r - mid;
    int *left = new int[n];
    int *right = new int[m];

    for (int i = 0; i < n; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < m; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n && j < m)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n)
        arr[k++] = left[i++];

    while (j < m)
        arr[k++] = right[j++];
}

// Divide and conqurer part
void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {9, 100, 5, 1, -1, 0, 8, 7, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    // printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}