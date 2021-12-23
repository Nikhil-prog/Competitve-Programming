/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

class my_deque
{
	// Members of a dequeue
	int *deq; // or use vector
	int head;
	int tail;
	int capacity;
	int size;

public:
	// constructor
	my_deque(int cap)
	{
		this->capacity = cap;
		deq = new int[cap];
		head = 1;
		tail = 0;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isFull()
	{
		return size == capacity;
	}

	void insertFront(int num)
	{
		// if dequeue is already full
		if (isFull())
			return;
		// update the head pointer considering array to be circular
		head = (head - 1 + capacity) % capacity;
		deq[head] = num;
		size++;
	}

	void insertLast(int num)
	{
		// if dequeue is already full
		if (isFull())
			return;
		// update the head pointer considering array to be circular
		tail = (tail + 1) % capacity;
		deq[tail] = num;
		size++;
	}

	int getFront()
	{
		// -1 represents that dequeue is empty
		if (isEmpty())
			return -1;
		return deq[head];
	}

	int getLast()
	{
		// -1 represents that dequeue is empty
		if (isEmpty())
			return -1;
		return deq[tail];
	}

	void deleteFront()
	{
		if (isEmpty())
			return;
		head = (head + 1) % capacity;
		size--;
	}

	void deleteLast()
	{
		if (isEmpty())
			return;
		tail = (tail - 1 + capacity) % capacity;
		size--;
	}

	void printDequeue()
	{
		if (isEmpty())
		{
			cout << "Dequeue is empty\n";
			return;
		}

		cout << "Dequeue contains elements as:\n";
		int i = head;
		while (true)
		{
			cout << deq[i] << " ";
			if (i == tail)
			{
				break;
			}
			i = (i + 1) % capacity;
		}
		cout << "\n";
	}
};

int main()
{
	my_deque d(3);
	d.printDequeue();
	d.insertLast(1);
	d.insertLast(2);
	d.insertFront(3);
	d.insertFront(4);
	d.printDequeue();
	d.deleteLast();
	d.insertFront(4);
	d.printDequeue();
	return 0;
}
