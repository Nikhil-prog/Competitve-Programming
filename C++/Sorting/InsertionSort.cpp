/*Nikhil*/
#include <iostream>
using namespace std;

void insertionSort(int *arr, int size)
{
    for (int i = 1; i <size; i++)
    {
        int currValue = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > currValue)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currValue;
    }
}


int main()
{
    int arr[] = {2, 9, -1, 5, 10, 1, 0, -7};
    insertionSort(arr, 8);

    //print sorted array
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
