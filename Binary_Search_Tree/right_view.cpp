/*

Problem 199 : Binary Tree Right Side View
Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

We need the rightmost node at each level of the tree.
Start from the root node at level 0.
If the node is NULL, 
    return.
If this is the first node visited at this level, 
    add it to ans.
First go to the right child.
Then go to the left child.
Because we go right first, the first node we visit at each level is the rightmost node.
Repeat this for all nodes.
Return ans.

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recursionRightView(TreeNode* root, int level,vector<int> &ans) 
    {
        if (root == nullptr)
            return;

        if(level == ans.size())
            ans.push_back(root->val);

        recursionRightView(root->right,level+1,ans);
        recursionRightView(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        recursionRightView(root,0,ans);
        return ans;
    }
};