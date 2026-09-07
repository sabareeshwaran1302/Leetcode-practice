/*
Problem Link : https://leetcode.com/problems/next-greater-element-i/
Problem 496 : Next Greater Element I

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
 If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


1.Create an answer vector
- ans stores the next greater element for every element in nums1.

2.Take each element from nums1
- The outer loop:
for(int i=0; i<nums1.size(); i++)
- We process one nums1[i] at a time.

3.Find that element inside nums2
- The inner loop searches for the position of nums1[i] in nums2.
    if(nums1[i] == nums2[j])

4.Look at all elements to its right
- Once found at index j, you check:
    for(int k=nums2.size()-1; k>j; k--)
- So, only elements after nums2[j] are considered.

5.Find elements greater than the current element    
    if(nums2[k] > nums2[j])
        - If an element is greater, you put it into st.

6.Why are you traversing from right to left?
- You start from the last element and move toward j.
- Therefore, among the greater elements you find, the last one pushed into st is the closest greater element to nums2[j].

7.Check the stack
- If no greater element was found:
    if(st.empty())
        ans.push_back(-1);
- Otherwise:
    ans.push_back(st.back());
        - st.back() gives the closest greater element found.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        vector<int>st;
        int pos=-1;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    while(!st.empty())
                    {
                        st.pop_back();
                    }
                    pos=j;
                    for(int k=(nums2.size())-1;k>j;k--)
                    {
                        if(nums2[k]>nums2[j])
                        {
                            st.push_back(nums2[k]);
                        }
                    }
                    if(st.empty())ans.push_back(-1);
                    else
                    {
                        ans.push_back(st.back());
                    }
                }

            }
        }
        return ans;
        
    }
};