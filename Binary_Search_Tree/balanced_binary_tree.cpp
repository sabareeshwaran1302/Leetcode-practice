/*
A binary tree is balanced if, at every node:

|height(left subtree) - height(right subtree)| <= 1

Given a binary tree, determine if it is height-balanced.


Define a recursive function height(root) to calculate the height of a subtree.
If root is NULL, return 0.

Recursively calculate the height of the left subtree:
        leftHeight = height(root->left)
If leftHeight == -1, 
    return -1 because the left subtree is already unbalanced.

Recursively calculate the height of the right subtree:
        rightHeight = height(root->right)
If rightHeight == -1, 
    return -1 because the right subtree is already unbalanced.

Calculate the difference between the left and right heights.

If:

    |leftHeight - rightHeight| > 1
        return -1 because the current node is unbalanced.

Otherwise, return the height of the current subtree:
    1 + max(leftHeight, rightHeight)

In isBalanced():
If height(root) != -1, 
    return true.
Otherwise, 
    return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int leftheight=height(root->left);
        if(leftheight==-1)
            return -1;
        int rightheight=height(root->right);
        if(rightheight==-1)
            return -1;
        if(abs(leftheight-rightheight) > 1)
            return -1;
        return 1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(height(root) != -1)
            return true;
        return false;   
    }
};