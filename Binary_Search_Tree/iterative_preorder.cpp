/*
Iterative Preorder Traversal of BST using Stack

root->left->right

push the root into stack and pop it and 
push its right child and then left child into stack and 
repeat the process until stack becomes empty.

*/

class PreorderTraversal
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
        int val[MAX_SIZE];
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

    Bool push(Stack *s, int val)
    {
        if (isFull(*s))
        {
            return FALSE;
        }

        s->top = s->top + 1;
        s->val[s->top] = val;

        return TRUE;
    }

    Bool pop(Stack *s, int *val)
    {
        if (isEmpty(*s))
        {
            return FALSE;
        }

        *val = s->val[s->top];
        s->top = s->top - 1;

        return TRUE;
    }

    int peek(Stack s)
    {
        if (isEmpty(s))
        {
            return -9999;
        }

        return s.val[s.top];
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        Stack s = createStack();
        push(&s, root->val);
        while (!isEmpty(s))
        {
            int val;
            pop(&s, &val);
            ans.push_back(val);
            if (root->right)
                push(&s, root->right->val);
            if (root->left)
                push(&s, root->left->val);
        }
        return ans;
    }