/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Delete the ith element from the Min-heap
    while maintaining the min-heap property.
    given that 0 <= i <= size(heap)
*/

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

    void insert(int num)
    {
        if (sz == capacity)
            return;
        sz++;
        heap[sz - 1] = num;

        // up-heapify
        int i = sz - 1;
        while (i != 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    // iteration version of down-heapify
    void downHeapify(int i)
    {
        bool flag = true;
        while (flag)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < sz && heap[l] < heap[smallest])
            {
                smallest = l;
            }

            if (r < sz && heap[r] < heap[smallest])
            {
                smallest = r;
            }

            if (smallest != i)
            {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
            {
                flag = false;
            }
        }
    }

    // -1 return represents heap is empty,
    // replace it with INT_MIN if negative elements exists in heap
    int extractMin()
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

    // YOUR FUNCTION GOES HERE
    void delete_ith_element(int ith)
    {
        // bring ith element to the top using up-heapify
        while (ith != 0)
        {
            swap(heap[ith], heap[parent(ith)]);
            ith = parent(ith);
        }

        // swap it with last element and call down-heapify at root
        swap(heap[0], heap[sz - 1]);
        sz--;
        downHeapify(0);
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

    myheap.delete_ith_element(5);
    myheap.print();
    return 0;
}