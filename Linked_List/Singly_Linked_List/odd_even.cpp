/*

Problem Link : https://leetcode.com/problems/odd-even-linked-list/
Problem 328 : Odd Even Linked List  
Given the head of a singly linked list, 
group all the nodes with odd indices together followed by the nodes with even indices, 
and return the reordered list.

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==nullptr)
            return head;
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *evenHead=even;
        while(even && even->next)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};