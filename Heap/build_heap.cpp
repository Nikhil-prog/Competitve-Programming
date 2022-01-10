/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

// iteration version of down-heapify
void downHeapify(int *arr, int sz, int i)
{
    bool flag = true;
    while (flag)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < sz && arr[l] < arr[smallest])
        {
            smallest = l;
        }

        if (r < sz && arr[r] < arr[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
        else
        {
            flag = false;
        }
    }
}

// level-wise printing
void print(int *arr, int sz)
{
    int i = 0;
    int levelNum = 1;
    while (i < sz)
    {
        int j = 0;
        while (i < sz && j < levelNum)
        {
            cout << arr[i] << " ";
            j++;
            i++;
        }
        cout << "\n";
        levelNum *= 2;
    }
}

void buildHeap(int *arr, int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        downHeapify(arr, size, i);
    }
}

int main()
{
    int arr[] = {10, 55, 20, 60, 100, 2, 10, 20, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "\nBefore build\n";
    print(arr, size);
    buildHeap(arr, size);
    cout << "\nAfter build\n";
    print(arr, size);
    return 0;
}