/*Nikhil*/
#include <bits/stdc++.h>
using namespace std;

/*
    Problem statement:
    Given the head of a linked list,
    return the node where the cycle begins.
    If there is no cycle, return null.

    Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/
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

class Solution
{
public:
    ListNode *res = NULL;

    void findCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        else if (head->next == head)
        {
            res = head;
            return;
        }

        int num = head->val;
        head->val = INT_MAX;
        if (head->next->val == INT_MAX)
        {
            head->val = num;
            head->next->val = 0;
            return;
        }
        findCycle(head->next);
        if (head->val == 0)
            res = head;
        head->val = num;
    }

    ListNode *detectCycle(ListNode *head)
    {
        findCycle(head);
        return res;
    }
};

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
    /*cycle connected back to node e1*/
    e4->next = e1;

    /*Solution*/
    Solution sol;
    ListNode *cycleHead = sol.detectCycle(root);
    cout << "The Cycle begins at Node with value :" << cycleHead->val << endl;
    return 0;
}