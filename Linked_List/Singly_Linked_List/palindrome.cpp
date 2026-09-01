/*
Problem Link : https://leetcode.com/problems/palindrome-linked-list/
Problem 234 : Palindrome Linked List

Given the head of a singly linked list, 
return true if it is a palindrome.return false otherwise.  


Find the middle, 
reverse the second half, 
then compare the first half with the reversed second half.

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
    bool isPalindrome(ListNode* head) 
    {
      ListNode *slow=head;
      ListNode *fast=head;
      while(fast && fast->next)
      {
        slow=slow->next;
        fast=fast->next->next;
      } // finding the middle of the linked list which is pointed by slow pointer.
      ListNode *prev=nullptr;
      ListNode *next=nullptr;
      while(slow) 
      {
        next=slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;
      } // reversing the second half of the linked list which is pointed by prev pointer.
      ListNode *t1=head;
      ListNode *t2=prev;
      while(t1 && t2)
      {
        if(t1->val != t2->val)
        {
            return false;
        }
        t1=t1->next;
        t2=t2->next;
      }
      return true;

        
    }
};