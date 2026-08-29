/*
15. 3Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

/*
Problem: 3Sum

Algorithm:
1. Sort the array.
2. Fix one element nums[i].
3. Use two pointers:
      left = i + 1
      right = n - 1
4. Find sum = nums[i] + nums[left] + nums[right].
5. If sum == 0:
      - Store the triplet.
      - Move left++ and right--.
      - Skip duplicate values of left.
      - Skip duplicate values of right.
6. If sum < 0:
      - Move left++ to increase the sum.
7. If sum > 0:
      - Move right-- to decrease the sum.
8. Skip duplicate values of i.
9. Continue until all triplets are found.

Pattern:
Sorting + Two Pointers

Time Complexity:
O(n²)

Space Complexity:
O(1) (excluding output)

Mistakes I Made:
1. Sorted inside the loop.
2. Used while(left <= right).
3. Calculated sum only once.
4. Used right++ instead of right--.
5. Broke the loop after finding one triplet.
6. Checked duplicates before finding a valid triplet.
7. Compared duplicates with left+1/right-1 instead of left-1/right+1 after moving pointers.
8. Forgot boundary check (left < right) while skipping duplicates.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            if (i>0 && nums[i] == nums[i - 1]) {
                continue;
            }
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left<right && nums[left] == nums[left - 1]) {
                    left++;
                } while (left <right && nums[right] == nums[right + 1]) {
                    right--;
                }
                } else if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                }
            }
        }
        return ans;
    }
};
