/*

LEVEL ORDER TRAVERSAL

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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans; // store complete tree
        if(root == nullptr)
            return ans;
        Queue q;
        enqueue(q,root); // adding the root value to queue
        while(q.front != q.rear) // run till queue  becomes empty
        {
            int size=q.rear - q.front;
            vector<int>level; //storing values of each level
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
            ans.push_back(level);
        }
        return ans;
    }
};