/*
Problem Link : https://leetcode.com/problems/middle-of-the-linked-list/
Problem 876 : Middle of the Linked List

Given the head of a singly linked list, 
return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

1. Create two pointers:
   - slow → moves one node at a time
   - fast → moves two nodes at a time
2. Start both pointers at head.
3. Move slow by 1 step and fast by 2 steps.
4. Continue until fast reaches the end.
5. When fast reaches the end, slow will be pointing to the middle node.
6. Return slow.

Fast reaches the end → Slow reaches the middle.


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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next)
        {
            slow=slow->next; // moves one node at a time
            fast=fast->next->next; // moves two nodes at a time
        }
        return slow; 
    }
};