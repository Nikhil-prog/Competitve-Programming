/*Nikhil*/
#include <iostream>
using namespace std;

class stack
{
    struct Node
    {
        int data;
        Node *next;
        Node(int num)
        {
            this->data = num;
            this->next = NULL;
        }
    };

    //top of stack
    Node *head = NULL;
    int sz = 0;

public:
    void push(int num)
    {
        Node *temp = new Node(num);
        temp->next = head;
        head = temp;
        sz++;
    }

    bool isEmpty()
    {
        return sz == 0;
    }

    void pop()
    {
        if (sz != 0)
        {
            head = head->next;
            sz--;
        }
    }

    int size()
    {
        return sz;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    stack myst;
    myst.push(40);
    myst.push(30);
    myst.print();
    myst.pop();
    myst.push(10);
    myst.print();
    return 0;
}
