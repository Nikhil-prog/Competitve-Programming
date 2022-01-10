/*Nikhil*/
#include <iostream>
using namespace std;

// returns rightmost element's index if multiple exists
int rightBinarySearch(int *arr, int size, int num)
{
    int low = 0;
    int high = size - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            res = mid;
            low = mid + 1;
        }
        else if (arr[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 5, 6, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << rightBinarySearch(arr, size, 2) << endl;
    return 0;
}
