/*

Problem Link : https://leetcode.com/problems/delete-node-in-a-bst/
Problem 450 : Delete Node in a BST

Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

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
TreeNode *findMin(TreeNode *t)
{
    while(t->left)
        t=t->left;

    return t;
}
 TreeNode* deleteNode(TreeNode* t, int data) {
        
    if(!t)
        return NULL;

    if(data<t->val)
    {
        t->left=deleteNode(t->left,data);
    }
    else if(data>t->val)
    {
        t->right=deleteNode(t->right,data);
    }
    else
    {
        /* No child */
        if(!t->left && !t->right)
        {
            delete t;
            return NULL;
        }

        /* Only right child */
        if(!t->left)
        {
            TreeNode *temp=t->right;
            delete t;
            return temp;
        }

        /* Only left child */
        if(!t->right)
        {
            TreeNode *temp=t->left;
            delete t;
            return temp;
        }

        /* Two children */
        TreeNode *temp=findMin(t->right);

        t->val=temp->val;

        t->right=deleteNode(t->right,temp->val);
    }

    return t;
}

};
