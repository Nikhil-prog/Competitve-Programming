/*Nikhil*/
#include <iostream>
using namespace std;

//returns leftmost element's index if multiple exists
int leftBinarySearch(int *arr, int size, int num)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            if (mid == 0)
            {
                return mid;
            }
            else if (arr[mid - 1] == num)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
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
    return -1;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 5, 6, 8, 8};
    cout << leftBinarySearch(arr, 9, 2) << endl;
    return 0;
}