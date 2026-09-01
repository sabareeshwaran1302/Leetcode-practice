/*
Problem Link : https://leetcode.com/problems/linked-list-cycle/
Problem 141 : Linked List Cycle

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.


Create two pointers:- slow → moves 1 step
- fast → moves 2 steps
Start both at head.
Move them while fast and fast->next are not nullptr.
After each movement:-
     If slow == fast, 
        a cycle exists → return true.
If fast reaches nullptr, 
    there is no cycle → return false.


If fast reaches NULL, there is no cycle; 
if fast catches slow, there is a cycle.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
        
    }
};