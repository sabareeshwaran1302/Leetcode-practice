/*

Find the maximum depth of a binary tree.
Depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.


if root is NULL, return 0.

Find the maximum depth of the left subtree by recursively calling:

        leftDepth = maxDepth(root->left)

Find the maximum depth of the right subtree by recursively calling:

        rightDepth = maxDepth(root->right)
Compare leftDepth and rightDepth.
Take the larger depth.
Add 1 for the current node.
Return the result.

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
 **/


class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l, r) + 1;
    }
};