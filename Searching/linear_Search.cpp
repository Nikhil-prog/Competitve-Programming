/*Nikhil*/
#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 5, 9, 1, 3, 0, -9, -7, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << linearSearch(arr, size, -9) << endl;
    return 0;
}
