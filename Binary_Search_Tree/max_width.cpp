/*

Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
Problem 662 :  Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.


1.Do Levelorder traversal and also store the index of each node in the queue. 
    The index of the left child is 2*index+1 and the index of the right child is 2*index+2.
2. For each level, calculate the width by subtracting the index of the first node from the index of the last node and adding 1.
3.We can normalize the indices by subtracting the index of the first node from all indices in that level to avoid integer overflow.

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
struct Item
{
    TreeNode *node; // pointer to the tree node
    int index; // index of the node in the level order traversal
};
struct Q
{
    Item arr[10000]; // array to store the items (Nodes + indices) in the queue
    int front;
    int rear;
};

void init(Q *q)
{
    q->front=0;
    q->rear=0;
}

bool isempty(Q q)
{
    return q.front==q.rear;
}

bool isfull(Q q)
{
    return q.rear==10000;
}

bool insert(Q *q,TreeNode *node,long long index)
{
    if(isfull(*q))
    {
        return false;
    }

    q->arr[q->rear].node=node; // to access q -> is needed . But to access member of struct Item we need "." since index is member of Item and Not a member of struct Q.
    q->arr[q->rear].index = index; //But to access member of struct Item we need "." since index is member of Item and Not a member of struct Q.
    q->rear++;
    return true;
}

bool pop(Q *q,TreeNode **node,long long *index)
{
    if(isempty(*q))
    {
        return false;
    }

    *node = q->arr[q->front].node;
    *index = q->arr[q->front].index;

    q->front++;

    return true;
}

bool peek(Q *q,TreeNode **node,long long *index)
{
    if(isempty(*q))
    {
        return false;
    }

    *node = q->arr[q->front].node;
    *index = q->arr[q->front].index;

    return true;
}


    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) 
            return 0;
        Q q;
        init(&q);

        insert(&q , root ,0);
        int maxWidth = 0;

        while(!isempty(q))
        {
            int size = q.rear - q.front;

            int first = q.arr[q.front].index; // index of the first node in the current level
            int last = 0; // index of the last node in the current level which will be updated in the loop below.
                        //So at end of the each loop iteration, last will contain the index of the last node in the current level.

            for(int i= 0;i< size;i++)
            {
                TreeNode *node;
                long long index;

                pop(&q , &node, &index);

                index = index - first; // Normalize the index to avoid integer overflow.if first index is 1000 and we need index 1005,instead of storing 1005, we can store 5. So we subtract first from all indices in that level. 

                last = index; // update the last index to the current node's index

                if(node->left)
                    insert(&q , node->left, 2*index+1);
                if(node->right)
                    insert(&q , node->right , 2*index+2);
            }
            int width  = last + 1; // width of the current level is last index - first index + 1. But since we normalized the indices, first index is 0, so width = last + 1.
            if(width > maxWidth )
                maxWidth = width;
        }
        return maxWidth;

    }
};