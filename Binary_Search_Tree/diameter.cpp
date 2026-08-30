/*
Problem 543: Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

if root == NULL, return 0.
Find the left height recursively.
Find the right height recursively.
Diameter through current node = left height + right height.
Update the maximum diameter.
Return the height of current node:
1 + max(left, right).
Finally, return the stored diameter.

*/

class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root) // finding the height of each node and simultaneously updating the diameter
    {
        if(root == nullptr)
            return 0;

        int l = height(root->left); // findingt the height of left subtree
        int r = height(root->right); // finding the height of right subtree 

        diameter = max(diameter, l + r); // left height + right height = diameter through current node. Update the maximum diameter. 

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        height(root);       // calculates heights and stores diameter
        return diameter;    // return the stored diameter
    }
};