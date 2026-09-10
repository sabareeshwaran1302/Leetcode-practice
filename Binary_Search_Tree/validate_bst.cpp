/*
Problem Link : https://leetcode.com/problems/validate-binary-search-tree/
Problem 98 : Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 




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
    bool Validate(TreeNode *root,long long min,long long max)
    {
        if(root == nullptr)
            return true;
        if(root->val <= min || root->val >= max)
            return false;
        return Validate(root->left,min,root->val) && Validate(root->right , root -> val ,max);
    }
    bool isValidBST(TreeNode* root) 
    {
        return Validate(root,LLONG_MIN , LLONG_MAX);
    }
};