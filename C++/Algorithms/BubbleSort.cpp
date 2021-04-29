/*Nikhil*/

//Bubbble Sort that sort the array within
//the range of [index "fromIndex" to index "inIndex"]
//if you want to run it on whole array
//Simply pass argument OR Replace as follow
//[fromIndex,toIndex] -> [0, ArraySize-1]
//TIME COMPLEXITY - (best, average, worst) -> (n, n^2, n^2)
//where n: length of part of array to be sorted
void bubbleSort(int *arr, int fromIndex, int toIndex)
{
    for (int i = fromIndex; i <= toIndex - 1; i++)s
    {
        for (int j = fromIndex; j <= toIndex - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tempValue = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempValue;
            }
        }
    }
    return;
}