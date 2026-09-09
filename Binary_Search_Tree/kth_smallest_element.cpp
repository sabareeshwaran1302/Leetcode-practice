/*

Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Problem 230 : Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Do Level Order Traversal and store the values in a vector. 
Sort the vector(the vector will be in ascending order) and return the kth smallest value.
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
 #define MAX 10000
struct Queue
{
    TreeNode* arr[MAX]; // storing nodes so that we can access its left and right nodes
    int front = 0;
    int rear = 0;
};
void enqueue(Queue &q, TreeNode* val)
{
    if(q.rear == MAX)
    {
        cout << "Queue Overflow\n";
        return;
    }
    q.arr[q.rear] = val;
    q.rear++;
}
void dequeue(Queue &q)
{
    if(q.front == q.rear)
    {
        cout << "Queue Underflow\n";
        return;
    }
    q.front++;
}
TreeNode* peek(Queue &q)
{
    if(q.front == q.rear)
    {
        cout << "Queue is empty\n";
        return nullptr;
    }
    return q.arr[q.front];
}
    
    int kthSmallest(TreeNode* root, int k) {

        if(root == nullptr)
            return -9999;
        vector<int>level; //vector that stores the values of all the nodes in the tree
        Queue q;
        enqueue(q,root); // adding the root value to queue
        while(q.front != q.rear) // run till queue  becomes empty
        {
            int size=q.rear - q.front;
            for(int i=0;i<size;i++) // how many nodes are in current level
            {
                TreeNode *temp=peek(q); //storing the node
                dequeue(q); // removing it
                level.push_back(temp->val); // pushing the value of the current node
                if(temp -> left)
                    enqueue(q,temp->left);
                if(temp -> right)
                    enqueue(q,temp ->right);
            }
        }
        sort(level.begin(),level.end()); // sorting the vector in ascending order
        return level[k-1]; // -1 as the vector is 0 indexed and k is 1 indexed
    }

};