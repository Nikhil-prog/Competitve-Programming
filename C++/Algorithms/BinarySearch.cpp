/*Nikhil*/

// function To search a number 'num' in array 'arr' within
// range of [low, high] index
// returns -1 in case of not exist
// TIME COMPLEXITY - O(log (n) )
// where n: length of part of array on which search is applied
int binarySearch(int *arr, int low, int high, int num)
{
    while (low <= high)
    {
        // it is same as (low+high)/2 but to avoid
        // any overflow of int value while adding
        int mid = low + (high - low) / 2;

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
