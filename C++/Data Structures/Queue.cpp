/*Nikhil*/
#include <iostream>
using namespace std;

class queue
{
    struct Node
    {
        int data;
        Node *next;
        Node(int num)
        {
            this->data = num;
        }
    };

    // attributes of a queue
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void enque(int num)
    {
        Node *temp = new Node(num);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        sz++;
    }

    void deque()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete (temp);
        if (head == NULL)
            tail = NULL;
        sz--;
    }

    int size()
    {
        return sz;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int getFront()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    int getBack()
    {
        if (head == NULL)
            return -1;
        return tail->data;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    queue myQueue;
    myQueue.enque(30);
    myQueue.enque(40);
    myQueue.enque(50);

    cout << "Before deque: " << endl;
    cout << "The size of queue is " << myQueue.size() << endl;
    cout << "The first element is " << myQueue.getFront() << endl;
    cout << "The last element is " << myQueue.getBack() << endl;
    myQueue.print();

    myQueue.deque();

    cout << "\nAfter deque: " << endl;
    cout << "Before deque " << endl;
    cout << "The size of queue is " << myQueue.size() << endl;
    cout << "The first element is " << myQueue.getFront() << endl;
    cout << "The last element is " << myQueue.getBack() << endl;
    myQueue.print();
    return 0;
}