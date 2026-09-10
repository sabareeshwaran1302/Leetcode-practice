/*
Problem Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Problem 235 : Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T
that has both p and q as descendants (where we allow a node to be a descendant of itself).”

1. Start from the root.
2. Check the values of p and q with root.
3. If both are smaller than root → go left.
4. If both are greater than root → go right.
5. Otherwise → root is the LCA.
   - They are on different sides, or
   - One of them is the root itself.
6. Keep doing this until you find the LCA.

Easy way to remember
Both left → LEFT
Both right → RIGHT
Different sides → ROOT (LCA)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == nullptr)
            return root;
        while(root)
        {
            if(p->val < root->val && q->val < root->val)
                root = root->left;
            else if(p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }
        return root;
        
    }
};