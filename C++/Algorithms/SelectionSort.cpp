/*Nikhil*/

//Selection Sort that sort the array within
//the range of [index "fromIndex" to index "inIndex"]
//if you want to run it on whole array
//Simply pass argument OR Replace as follow
//[fromIndex,toIndex] -> [0, ArraySize-1]
//TIME COMPLEXITY - (best, average, worst) -> (n^2, n^2, n^2)
//where n: length of part of array to be sorted
void selectionSort(int *arr,int fromIndex,int toIndex)
{
    for (int i=fromIndex;i<=toIndex-1;i++)
    {
        int minIndex = i;
        for (int j=i+1;j<=toIndex;j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }

        //swap part of selection sort
        int tempVaule = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tempVaule;
    }
    return;
}