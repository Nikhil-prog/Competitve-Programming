/*Nikhil*/
#include <iostream>
using namespace std;

//TIME COMPLEXITY - (best, average, worst) -> (n, n, n)
int mostContiguousFrequentElement(int *arr, int size)
{
    int maxFreq = -1;
    int mostFreqElement=-1;
    
    int lastElement = -1;
    int freq = 0;
    for (int i = 0; i < size; i++)
    {
       if (arr[i] == lastElement)
        {
            freq++;
        }
        else
        {
            lastElement = arr[i];
            freq = 1;
        }

        if (freq > maxFreq)
        {
            maxFreq = freq;
            mostFreqElement = arr[i];
        }
    }

    //return maxFreq;  //use this for maximum frequency
    return mostFreqElement;
}

int main()
{
    int arr[] = {-1,-1,2,2,2,2,3,3,3,4};
    cout<<mostContiguousFrequentElement(arr,10)<<endl;
    return 0;
}
