/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    // Members of min-heap
    int capacity;
    int sz;
    int *heap;

public:
    minHeap(int cap)
    {
        this->capacity = cap;
        this->sz = 0;
        this->heap = new int[capacity];
    }

    int left(int i)
    {
        return 2 * i + 1;
    }

    int right(int i)
    {
        return 2 * i + 2;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    bool isEmpty()
    {
        return sz == 0;
    }

    int size()
    {
        return sz;
    }

    void insert(int num)
    {
        if (sz == capacity)
            return;
        sz++;
        heap[sz - 1] = num;

        // up-heapify
        int i = sz - 1;
        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    /* Recursion version of downHeapify
    void downHeapify(int i)
    {
        int l = left(i);
        int r = right(i);

        int largest = i;
        if (l<sz && heap[l]>heap[largest])
        {
            largest = l;
        }

        if (r<sz && heap[r] > heap[largest])
        {
            largest = r;
        }

        if (largest!=i)
        {
            swap(heap[i], heap[largest]);
            downHeapify(largest);
        }
    }*/

    // iteration version of down-heapify
    void downHeapify(int i)
    {
        bool flag = true;
        while (flag)
        {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if (l < sz && heap[l] > heap[largest])
            {
                largest = l;
            }

            if (r < sz && heap[r] > heap[largest])
            {
                largest = r;
            }

            if (largest != i)
            {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
            {
                flag = false;
            }
        }
    }

    // -1 return represents heap is empty,
    // replace it with INT_MIN if negative elements exists in heap
    int extractMax()
    {
        if (sz == 0)
        {
            return -1;
        }
        else if (sz == 1)
        {
            sz--;
            return heap[0];
        }

        sz--;
        swap(heap[0], heap[sz]);
        downHeapify(0);
        return heap[sz];
    }

    // level-wise printing
    void print()
    {
        int i = 0;
        int levelNum = 1;
        while (i < sz)
        {
            int j = 0;
            while (i < sz && j < levelNum)
            {
                cout << heap[i] << " ";
                j++;
                i++;
            }
            cout << "\n";
            levelNum *= 2;
        }
    }
};

int main()
{
    minHeap myheap(15);

    myheap.insert(10);
    myheap.insert(15);
    myheap.insert(2);
    myheap.insert(50);
    myheap.insert(100);
    myheap.insert(55);
    myheap.insert(20);
    myheap.print();
    cout << "max num is " << myheap.extractMin() << endl;
    myheap.print();
    return 0;
}