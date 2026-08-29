/*
Problem 501

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if(root==nullptr)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) 
    {
        vector<int>temp; // storing complete values of bst
        vector<int>ans; // storing mode values of bst
        inorder(root,temp); // calling inorder function
        int count=1;
        int maxcount=1;
        ans.push_back(temp[0]); //handling single node case
        for(int i=1;i<temp.size();i++)
        {
            if(temp[i-1] == temp[i]) // comparing current and previous element
                count++;
            else
                count=1;
            if(count > maxcount)
            {
                ans.clear(); // if current count is greater than maxcount then clear the ans vector and push the current element into it
                ans.push_back(temp[i]);
                maxcount=count;
            }
            else if(count==maxcount) // if two values occur same number times then push both values into ans vector
                ans.push_back(temp[i]);
        }
        return ans;
    }
};