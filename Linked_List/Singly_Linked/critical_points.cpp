/*

Problem 2058 : Find the Minimum and Maximum number of Nodes between Critical Points.

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] 
where minDistance is the minimum distance between any two distinct critical points and 
maxDistance is the maximum distance between any two distinct critical points. 
If there are fewer than two critical points, return [-1, -1].

Algorithm : 
1.Traverse the linked list using prev, curr and next pointers.
2. For each node with both prev and next:
   - If curr is smaller than both → local minimum.
   - If curr is greater than both → local maximum.
   - Store its 0-based index in temp.
3. Sort the critical point indices.
4. If there are fewer than 2 critical points,
   return {-1, -1}.
5. Find the minimum distance between consecutive critical points.
6. Find the maximum distance between the first and last
   critical points.
7. Return {minDistance, maxDistance}.

Time Complexity: O(N log N)
Space Complexity: O(N)

*/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>ans;
        if(head == nullptr)
        {
            return ans;
        }
        vector<int>temp;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=head->next;
        int count=0;
        while(curr)
        {
            count++;
            if(prev && next)
            {
                if((curr->val < prev->val) && (curr->val < next->val))
                {
                    temp.push_back(count -1);
                }
                else if((curr->val > prev->val) && (curr->val > next->val))
                {
                    temp.push_back(count -1);
                }
            }
            prev=curr;
            curr=curr->next;
            if(curr)
                next=curr->next;
        }
        sort(temp.begin() , temp.end());
        if(temp.size() < 2)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int minDis = INT_MAX;
        for(int i = 1; i < temp.size(); i++)
        {   
            minDis = min(minDis, temp[i] - temp[i-1]);
        }
        int maxDis = temp[temp.size()-1] - temp[0];
        ans.push_back(minDis);
        ans.push_back(maxDis);
        return ans;
    }
};