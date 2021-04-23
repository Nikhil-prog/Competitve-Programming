/*Nikhil*/

//Insertion Sort that sort the array within
//the range of [index "fromIndex" to index "inIndex"]
//if you want to run it on whole array
//Simply pass argument OR Replace as follow
//[fromIndex,toIndex] -> [0, ArraySize-1]
//TIME COMPLEXITY - (best,average,worst) -> (n, n^2 , n^2)
//where n: lenght of part of array to be sorted
class InsertionSort 
{
    static void InsertionSort(int[] arr, int fromIndex, int toIndex) 
    {
        for (int i = fromIndex + 1; i <= toIndex; i++) 
        {
            int currValue = arr[i];
            int j = i - 1;

            while (j >= fromIndex && arr[j] > currValue) 
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = currValue;
        }
        return;
    }
}
