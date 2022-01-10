/*Nikhil*/
#include <iostream>
using namespace std;

void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap part of selection sort
        int tempVaule = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tempVaule;
    }
}

int main()
{
    int arr[] = {2, 9, -1, 5, 10, 1, 0, -7};
    selectionSort(arr, 8);

    // print sorted array
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
