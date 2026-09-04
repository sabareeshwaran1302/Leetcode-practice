/*

Problem Link : https://leetcode.com/problems/smallest-stable-index-i/
Problem 3903 : Smallest Stable Index I

You are given an integer array nums of length n and an integer k.

For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:

max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.



*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int score=-1;
        for(int i=0;i<nums.size();i++)
        {
            int min=INT_MAX;
            int max=INT_MIN;
            for(int l=0;l<=i;l++) // Find Max element from 0 to i
            {
                if(nums[l] > max)
                {
                    max=nums[l];
                }

            }
            for(int j=i;j<nums.size();j++) // Find Min element from i to n-1
            {
                if(nums[j] < min)
                {
                    min=nums[j];
                }
            }
            score=max-min; // calculate score
            if(score<=k) // if score is less than or equal to k , return index position
                return i;            
        }
        return -1; // if element not exists return -1.
    }
};