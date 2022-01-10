/*Nikhil*/
#include <iostream>
using namespace std;

//function to merge two sorted array
void merge(int *arr1, int *arr2, int size1, int size2)
{
    int finalArray[size1 + size2];

    int p1 = 0;
    int p2 = 0;
    int p = 0;

    while (p1 < size1 && p2 < size2)
    {
        if (arr1[p1] <= arr2[p2])
        {
            finalArray[p++] = arr1[p1++];
        }
        else
        {
            finalArray[p++] = arr2[p2++];
        }
    }

    while (p1 < size1)
    {
        finalArray[p++] = arr1[p1++];
    }

    while (p2 < size2)
    {
        finalArray[p++] = arr2[p2++];
    }

    //printing mergered Array
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << finalArray[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 2, 3, 5, 15, 5000};
    int arr2[] = {10, 15, 20, 25, 50};
    merge(arr1, arr2, 6, 5);
    return 0;
}