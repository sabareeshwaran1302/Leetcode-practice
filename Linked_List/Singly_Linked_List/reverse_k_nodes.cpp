/*
Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Problem 25 : Reverse Nodes in K-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.


1. Find the kth node
   - findKthNode(temp, k) finds the kth node from temp.
   - If fewer than k nodes are present, it returns nullptr.
2. Check if k nodes are available
   if(kthNode == nullptr)
        - If not enough nodes are left, stop.
        - The remaining nodes stay unchanged.
3. Save the next group
   nextNode = kthNode->next;
   - Store where the next group starts.
4. Separate the current group
    kthNode->next = nullptr;
    - Disconnect the current group from the rest.
5. Reverse the current group
    kthNode = reverseList(temp);
        - Reverse those k nodes.
        - kthNode now points to the new first node.
6. Connect the reversed group
   - If it is the first group, update head.
   - Otherwise:
        prev->next = kthNode;
7. Move prev to the end of the reversed group
    prev = temp;
        - temp becomes the last node after reversal.
8. Move to the next group
    temp = nextNode;
9. Repeat
    - Keep doing the same until the list ends.
10. Return the new head
        return head;

In one line : 
Find k nodes → separate them → reverse them → connect them → move to the next k nodes → repeat.

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
    ListNode *findKthNode(ListNode *head,int k)
    {
        if(head == nullptr)
            return head;
        ListNode *temp=head;
        for(int i=0;i<k-1;i++)
        {
            temp=temp->next;
            if(temp==nullptr)
                return nullptr; // if there are not enough k nodes, return nullptr
        }
        return temp;
    }
    ListNode *reverseList(ListNode *head)
    {
        if(!head)
            return nullptr;
        ListNode *rprev=nullptr;
        ListNode *curr=head;
        ListNode *rnext=nullptr;
        while(curr)
        {
            rnext=curr->next;
            curr->next=rprev;
            rprev=curr;
            curr=rnext;
        }
        return rprev; // return the new head of the reversed list  
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp=head;
        ListNode *prev=nullptr;
        while(temp)
        {
            ListNode *kthNode = findKthNode(temp,k);
            if(kthNode == nullptr) // if there are not enough k nodes, return the head of the modified list
            {
                if(prev) // if prev is not null, connect the last processed node to the remaining nodes
                {
                    prev->next=temp;
                }
                break; // if there are not enough k nodes in the complete given list, break the loop and return the head of the given list.
            }
            ListNode *nextNode=kthNode->next; // store the next node after the kth node
            kthNode->next=nullptr; // disconnect the current group of k nodes from the rest of the list
            kthNode=reverseList(temp); // reverse the current group of k nodes and update kthNode to point to the new head of the reversed group
            if(temp==head) // if the current group is the first group, update head to point to the new head of the reversed group
            {
                head=kthNode;
            }
            else // if the current group is not the first group, connect the previous group's last node to the new head of the reversed group
            {
                prev->next=kthNode;
            }
            prev=temp; // update prev to point to the last node of the current group (which is now temp after reversal)
            temp=nextNode; // move temp to the first node of the next group to be processed
        }
        return head;
    }
};