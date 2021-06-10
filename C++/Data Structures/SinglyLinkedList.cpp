/*Nikhil*/
#include <iostream>
using namespace std;

/******************************Singly Linked List*******************************/
class singlyLinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int num)
        {
            data = num;
            next = NULL;
        }
    };

    //Head of singly Linked list
    Node *head = NULL;

public:
    void insertBegin(int num)
    {
        Node *newNode = new Node(num);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int num)
    {
        Node *newNode = new Node(num);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    void insertAt(int num, int index)
    {
        Node *newNode = new Node(num);
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;
        for (int i = 0; i <= index - 2 && curr != NULL; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            return;
        newNode->next = curr->next;
        curr->next = newNode;
    }

    //Use this only when you are making sorted linkedList
    void insertSort(int num)
    {
        Node *newNode = new Node(num);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else if (head->data >= num)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;
        while (curr->next != NULL && curr->next->data < num)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    //this can only remove consecutive duplicates
    void removeDuplicates()
    {
        if (head == NULL)
            return;
        Node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->next->data == curr->data)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
        }
    }

    int getIndex(int num)
    {
        int index = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->data == num)
            {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }

    void deleteHead()
    {
        if (head == NULL)
            return;
        head = head->next;
    }

    void deleteTail()
    {
        if (head == NULL || head->next == NULL)
        {
            head = NULL;
            return;
        }

        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = NULL;
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }

    void printMiddle()
    {
        if (head == NULL)
            return;
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->data << endl;
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
    singlyLinkedList list;
    list.insertBegin(1);
    list.insertBegin(5);
    list.insertEnd(22);
    list.insertAt(100, 1);
    list.print();
    list.reverse();
    list.print();
    list.printMiddle();
    list.print();
    return 0;
}