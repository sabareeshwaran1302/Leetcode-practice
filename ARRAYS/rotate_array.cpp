/*
Problem Link : https://leetcode.com/problems/rotate-array/
Problem 189 : Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Suppose:
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
We want:
    [5, 6, 7, 1, 2, 3, 4]
Step 1: 
    k = k % n   
        If k is greater than n, reduce unnecessary rotations.
    Example:
    k = 10, n = 7
    10 % 7 = 3
    So rotating 10 times is same as rotating 3 times.

Step 2: 
    Reverse the entire array
        reverse(nums.begin(), nums.end());
            [1, 2, 3, 4, 5, 6, 7]
                ↓
            [7, 6, 5, 4, 3, 2, 1]

Step 3: 
Reverse the first k elements
    reverse(nums.begin(), nums.begin() + k);
        First 3 elements:
            [7, 6, 5] → [5, 6, 7]
    Array becomes:
        [5, 6, 7, 4, 3, 2, 1]
Now the elements that need to move to the front are in the correct order.

Step 4: 
Reverse the remaining elements
    reverse(nums.begin() + k, nums.end());
    Remaining:
        [4, 3, 2, 1] → [1, 2, 3, 4]

Final:
[5, 6, 7, 1, 2, 3, 4]

The core idea to remember
Reverse everything → reverse the first k → reverse the remaining n-k.

*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;

        reverse(nums.begin(), nums.end());

        reverse(nums.begin(), nums.begin() + k);

        reverse(nums.begin() + k, nums.end());
    }
};