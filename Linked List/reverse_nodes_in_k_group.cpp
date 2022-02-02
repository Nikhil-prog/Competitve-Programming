/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given the head of a linked list,
    reverse the nodes of the list k at a time,
    and return the modified list.

    Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    bool flag = false;
    ListNode *prev = NULL, *tail = head;
    for (int i = 0; i < k; i++)
    {
        if (head == NULL)
        {
            flag = true;
            break;
        }
        ListNode *tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    if (flag)
    {
        head = prev;
        prev = NULL;
        while (prev != tail)
        {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
    }
    else
    {
        tail->next = reverseKGroup(head, k);
    }
    return prev;
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
    cout << "The Linked List before rotation in k group " << endl;
    print_LL(root);
    root = reverseKGroup(root, 2);
    cout << "The Linked List after rotation in k group " << endl;
    print_LL(root);
    return 0;
}