/*
Algorithm — Boundary Traversal of a Binary Tree

Boundary Traversal means visiting the nodes that form the outer boundary of a binary tree, 
in an anti-clockwise direction.

1. Root
2. Left Boundary
3. Leaf Nodes (left → right)
4. Right Boundary (bottom → top)


Step 1: Check whether a node is a leaf
    1. A node is a leaf if:
            - left == NULL
            - right == NULL
    2. Return true if both conditions are satisfied.


Step 2: Add the left boundary
    1. Start from the left child of the root.
    2. Continue until curr == NULL.
    3. If curr is not a leaf, 
        add its value to ans.
    4. If a left child exists, 
        move to the left child.
    5. Otherwise, 
        move to the right child.
    6. This gives the left boundary from top to bottom, excluding leaves.


Step 3: Add all leaf nodes
    1. Start from the root.
    2. If the current node is a leaf, 
        add its value to ans.
    3. Recursively traverse the left subtree.
    4. Recursively traverse the right subtree.
    5. This adds all leaf nodes in left-to-right order.


Step 4: Add the right boundary
    1. Start from the right child of the root.
    2. Create a temporary vector temp.
    3. Continue until curr == NULL.
    4. If curr is not a leaf, 
        add its value to temp.
    5. If a right child exists, 
        move to the right child.
    6. Otherwise,   
        move to the left child.
    7. Reverse temp.
    8. Add the reversed elements to ans.
    9. This gives the right boundary from bottom to top, excluding leaves.


Step 5: Boundary Traversal
1. If the root is NULL, return an empty vector.
2. Add the root to ans.
    ans.push_back(root->val);
3. Call addLeftBoundary().
4. Call addLeaves().
5. Call addRightBoundary().
6. Return ans.

*/

class BoundaryTraversal
{
public:
    bool isLeaf(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    void addLeftBoundary(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->left;

        while(curr)
        {
            if(!isLeaf(curr))
            {
                ans.push_back(curr->val);
            }

            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode *root, vector<int> &ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->val);
        }

        if(root->left)
            addLeaves(root->left, ans);

        if(root->right)
            addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->right;
        vector<int> temp;

        while(curr)
        {
            if(!isLeaf(curr))
            {
                temp.push_back(curr->val);
            }

            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        reverse(temp.begin(), temp.end());

        for(int i : temp)
        {
            ans.push_back(i);
        }
    }

    vector<int> boundaryTraversal(TreeNode *root)
    {
        vector<int> ans;

        if(root == nullptr)
            return ans;

        ans.push_back(root->val); 

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};