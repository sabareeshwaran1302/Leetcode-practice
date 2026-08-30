/*

Problem 100 : Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // Both are NULL → same
        if(!p && !q)
            return true;

        // One is NULL → different
        if(!p || !q)
            return false;

        // Values different → different
        if(p->val != q->val)
            return false;

        // Both left and right must be same
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};