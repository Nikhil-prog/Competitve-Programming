/*Nikhil*/
#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int num)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // it is same as (low+high)/2 but to avoid
        // any overflow of int value while adding

        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {-1, 1, 1, 2, 5, 9, 10, 111, 1200};
    cout << binarySearch(arr, 9, 5) << endl;
    return 0;
}
