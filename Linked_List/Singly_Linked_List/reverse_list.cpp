/*
Problem Link : https://leetcode.com/problems/reverse-linked-list/
Problem 206 : Reverse Linked List
Given the head of a singly linked list, reverse the list, 
and return the reversed list.

 1. Initialize three pointers:
   - prev = nullptr
   - curr = head
   - next = nullptr
2. Traverse the list while curr is not nullptr.
3. Store the next node in next.
4. Reverse the current node's link by pointing it to prev.
5. Move prev to curr.
6. Move curr to next.
7. After the loop, prev will be the new head.
8. Return prev.
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev=nullptr;
        ListNode *curr=head;
        ListNode *next=nullptr;
        while(curr!=nullptr)
        {
            next = curr->next;      // Save next node
            curr->next = prev;      // Reverse the link
            prev = curr;            // Move prev forward
            curr = next;            // Move curr forward
        }
        head=prev;
        return head;
    }
};