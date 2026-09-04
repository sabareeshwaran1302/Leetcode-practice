/*

Problem Link: https://leetcode.com/problems/rotate-list/
Problem 61 : Rotate List
Given the head of a linked list, rotate the list to the right by k places.


1. Check if the list is empty
   if(head == nullptr)
       return nullptr;
2. Find the length of the list
   - Traverse the list and count nodes.
   - Store it in len.
3. Remove unnecessary rotations
   int n = k % len;
   - Rotating len times gives the original list.
   - So only n rotations are needed.
4. If n == 0
        if(n == 0)
            return head;
   - No rotation is required.
5. Find the last node
   while(temp1->next)
       temp1 = temp1->next;
6. Make the list circular
   temp1->next = head;
   - Last node now points to the first node.
7. Find the new last node
   - Move len - n - 1 positions from the original head.
   - This node will become the new tail.
8. Set the new head
   head = temp2->next;
   - The node after the new tail becomes the new head.
9. Break the circular connection
   temp2->next = nullptr;
10. Return the new head
In one line:
Find length → k % len → make list circular → find new tail → make next node the head → break the circle.

Why len - n - 1?
In a linked list of length len, when the list is rotated right by n positions:
- The last n nodes move to the beginning.
- Therefore, the new head is at position len - n.
- The node immediately before the new head becomes the new tail.
- Since positions are zero-indexed, the new tail is at position:
            len - n - 1
            

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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==nullptr)
            return nullptr;
        int len=0;
        ListNode *temp1=head;
        while(temp1)
        {
            len++;
            temp1=temp1->next;
        }
        int n=k%len;
        if(n==0)
            return head;
        temp1=head;
        while(temp1->next)
        {
            temp1=temp1->next;
        }
        temp1->next=head;
        int p=0;
        ListNode *temp2=head;
        while(p<len-n-1 && temp2->next)
        {
            p++;
            temp2=temp2->next;
        }
        head=temp2->next;
        temp2->next=nullptr;
        return head;
    }

};