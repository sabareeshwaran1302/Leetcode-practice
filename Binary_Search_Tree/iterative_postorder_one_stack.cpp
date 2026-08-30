/*

Postorder Traversal using one stacks

*/
/*
Iterative Postorder Traversal of BST using Stack

left->right->root

Create an empty stack.
Set current = root.
Repeat while current is not NULL or stack is not empty:
if current is not NULL:
    Push current into the stack.
    move current to its left child.
else:
    assign temp to the right child of the top node in stack.
    if temp is NULL:
        pop the top node from stack and add its value to the answer.
        while stack is not empty and temp is the right child of the top node in stack:
            pop the top node from stack and add its value to the answer.
    else:
        move current to temp.
return ans


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
        Stack s=createStack();
        TreeNode *current=root;
        while( current != nullptr || !isEmpty(s))
        {
            if(current !=nullptr) // addinng left children
            {
                push(&s,current);
                current=current->left;
            }
            else // if there is no left children
            {
                TreeNode *temp = peek(s)->right; // store right child of top node in stack
                if(temp == nullptr) // if there is no right child
                {
                    temp=pop(&s);
                    ans.push_back(temp->val);
                    while(!isEmpty(s) && temp == peek(s)->right) // if the popped node is the right child of the top node in stack, pop the top node and add its value to answer
                    { // which means that we have processed the right nodes of the top node and we have to add top node(root) to the ans
                        temp=pop(&s);
                        ans.push_back(temp->val);
                    }
                }
                else // if there is a right child, move current to right child
                {
                    current=temp;
                }
            }
        }
        return ans;
    }