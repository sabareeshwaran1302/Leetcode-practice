/*
Problem 124: Binary Tree Maximum Path Sum

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Set maxval = INT_MIN.
If the current node is NULL, return 0.
Find the best sum from the left subtree.
Find the best sum from the right subtree.
If either sum is negative, 
    replace it with 0.
Calculate the path sum through the current node:
    leftSum + root->val + rightSum
Update maxval if this path sum is greater.

Return to the parent:
    root->val + max(leftSum, rightSum)

Only one side can be continued to the parent.

After processing the whole tree, return maxval.



*/
class Solution {
public:

    int maxval = INT_MIN;
    int maxSum(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int leftSum = max(0, maxSum(root->left));  // ignore negative sums, if leftSum is negative, we take 0 instead
        int rightSum = max(0, maxSum(root->right)); // if 0 is encountered we tells that we are not taking the negative value into calculation
        maxval = max(   maxval ,   leftSum + root->val + rightSum); // complete path sum through current node, left + root + right
        return root->val + max(leftSum, rightSum); // Parent can continue through only one side
    }


    int maxPathSum(TreeNode* root)
    {
        maxSum(root);
        return maxval;
    }
};