/*
Problem Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
Problem 2095 : Delete the Middle Node of a Linked List


Slow finds the middle, 
    prev stays behind slow, and then prev skips slow.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        if( head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=nullptr;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        return head;
    }
};