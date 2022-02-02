/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given the head of a linked list,
    rotate the list to the right by k places. where ( 0 <= k <= 2*1e9 )

    Problem Link: https://leetcode.com/problems/rotate-list/
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    ListNode *root = head, *tail = head;
    int n = 0;
    while (head != NULL)
    {
        if (head->next == NULL)
        {
            tail = head;
        }
        head = head->next;
        n++;
    }
    k = k % n;

    head = root;
    for (int i = 0; i < n - k - 1; i++)
    {
        head = head->next;
    }
    tail->next = root;
    tail = head->next;
    head->next = NULL;
    return tail;
}

void print_LL(ListNode *root)
{
    while (root != NULL)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main()
{
    ListNode *root = new ListNode(0);
    ListNode *e1 = new ListNode(1);
    ListNode *e2 = new ListNode(2);
    ListNode *e3 = new ListNode(3);
    ListNode *e4 = new ListNode(4);
    root->next = e1;
    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    cout << "The Linked List before rotation" << endl;
    print_LL(root);
    root = rotateRight(root, 2);
    cout << "The Linked List after rotation" << endl;
    print_LL(root);
    return 0;
}