/*

Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
Problem 26 : Remove Duplicates from Sorted Array


*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int temp=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(temp==nums.at(j))
                {
                    nums.erase(nums.begin()+j);
                    j--;
                }
            }
        }
       return nums.size();
    }
};