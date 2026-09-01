/*
Problem Link : https://leetcode.com/problems/sort-list/
Problem 148 : Sort List
Given the head of a linked list, return the list after sorting it in ascending order.


This problem can be solved using the merge sort algorithm. 
The idea is to divide the linked list into two halves, 
sort each half recursively, and then merge the two sorted halves.


The recursion will stop when the list is empty or has only one node,
which means it is already sorted. ie we are having only single node or no node in the list.
Left will be a single node and right will be a single node. 
Then we will merge Left and Right to get the sorted list..
At the next step,left and right will be two nodes each. Then we will merge left and right to get the sorted list of 4 nodes.
Doing this recursively will give us the Final sorted list.


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
    ListNode* findmiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = nullptr;
        ListNode* t1 = dummy;
        while (h1 && h2) {
            if (h1->val <= h2->val) {
                t1->next = h1;
                h1 = h1->next;
                t1 = t1->next;
            }
            else {
                t1->next = h2;
                h2 = h2->next;
                t1 = t1->next;
            }
        }
            if (h1) {
                while (h1) {
                    t1->next = h1;
                    h1 = h1->next;
                    t1 = t1->next;
                }
            }
            if (h2) {
                while (h2) {
                    t1->next = h2;
                    h2 = h2->next;
                    t1 = t1->next;
                }
            }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};