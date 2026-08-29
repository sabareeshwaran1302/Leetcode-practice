/*

Postorder Traversal using two stacks

*/
/*
Iterative Inorder Traversal of BST using Stack

left->root->right

Create an empty stack.
Set current = root.
Repeat while current is not NULL or stack is not empty:
Keep moving to the left:
Push current into the stack.
Set current = current->left.
When current becomes NULL:
Pop a node from the stack and assign it to current.
Add current->val to the answer.
Move to the right subtree:
current = current->right.
Repeat until both:
current == NULL
stack is empty.
Return the answer



*/

class PostorderTraversal
{
public:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

    typedef enum
    {
        FALSE,
        TRUE
    } Bool;

    typedef struct
    {
        TreeNode *val[MAX_SIZE];
        int top;
    } Stack;

    Stack createStack()
    {
        Stack s;
        s.top = 0;
        return s;
    }

    Bool isEmpty(Stack s)
    {
        return s.top == 0;
    }

    Bool isFull(Stack s)
    {
        return s.top == MAX_SIZE - 1;
    }

    Bool push(Stack *s, TreeNode *val)
    {
        if (isFull(*s))
        {
            return FALSE;
        }

        s->top = s->top + 1;
        s->val[s->top] = val;

        return TRUE;
    }

    TreeNode *pop(Stack *s)
    {
        if (isEmpty(*s))
        {
            return nullptr;
        }

        TreeNode *val=s->val[s->top];
        s->top=s->top-1;
        return val;
   }

    TreeNode *peek(Stack s)
    {
        if (isEmpty(s))
        {
            return nullptr;
        }

        return s.val[s.top];
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        Stack s = createStack();
        TreeNode* current=root;
        while (!isEmpty(s) || current != nullptr)
        {
            while(current != nullptr) // keep moving to the left
            {
                push(&s,current); // pushing the current node into stack
                current=current->left; // moving to the left node
            }
            current=pop(&s); // popping the top node from stack and assigning it to current
            ans.push_back(current->val); // adding the value of current node to the answer
            current=current->right; // moving to the right node
        }
        return ans;
    }