/*

Problem Link: https://leetcode.com/problems/symmetric-tree/
Problem 101 : Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself 
(i.e., symmetric around its center).


If the tree is empty, 
    return true.
Compare the left and right subtrees of the root.
If both nodes are NULL, 
    they are symmetric → return true.
If only one is NULL, 
    they are not symmetric → return false.
If their values are different, 
    return false.
Compare:- 
    left's left with right's right
    left's right with right's left
If both comparisons are symmetric, 
    return true

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
    bool isSymmetric(TreeNode* root) 
    {
       if(root == nullptr)
       {
            return true;
       }
       return isSymmetriclr(root->left,root->right);
    }
    bool isSymmetriclr(TreeNode *left,TreeNode *right)
    {
        if(left==nullptr && right==nullptr)
        {
            return true;
        }
        
        if(left==nullptr || right==nullptr)
        {
            return false;
        }

        if(left->val != right->val)return false;

        return isSymmetriclr(left->left,right->right) && isSymmetriclr(left->right , right->left);
    }
};