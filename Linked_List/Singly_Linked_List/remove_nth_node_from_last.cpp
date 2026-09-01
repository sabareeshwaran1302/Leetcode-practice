/*
Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Problem 19 : Remove Nth Node From End of List

Given the head of a linked list,
remove the nth node from the end of the list and 
return its head.  


Keep fast exactly n nodes ahead of slow.ie.maintain a gap of n nodes between fast and slow.
Then when fast reaches the end, 
slow will be just before the node we need to delete.


1. Create dummy before head
2. Put slow and fast at dummy
3. Move fast n+1 steps
4. Move slow and fast together
5. When fast reaches NULL,
        slow is before the node to delete
6. Skip that node:
        slow->next = slow->next->next
7. Return dummy.next

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode dummy(0);
        dummy.next=head;
        ListNode *slow=&dummy;
        ListNode *fast=&dummy;
        for(int i=0;i<=n;i++)
        {
            fast=fast->next;
        }
        while(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy.next;
    }
};