/*Nikhil*/
#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tempValue = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempValue;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 9, -1, 5, 10, 1, 0, -7};
    bubbleSort(arr, 8);

    // print sorted array
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
