/*

Preorder, Inorder and Postorder Traversal of Binary Tree using One Stack

We are traversing a single node 3 times and "State "Stores how many times it has traversed.

Create an empty stack.
Create three empty arrays/vectors:
    pre for Preorder
    in for Inorder
    post for Postorder
If root == NULL, stop.
Push the root into the stack with state = 1.
Repeat while the stack is not empty:
    Get the top node from the stack.
    If its state is 1:
        Add the node to pre.
        Change its state to 2.
        If the left child exists, 
            push the left child with state 1.
    Else if its state is 2:
        Add the node to in.
        Change its state to 3.
        If the right child exists, 
            push the right child with state 1.
    Else if its state is 3:
        Add the node to post.
        Pop the node from the stack.
When the stack becomes empty, print pre, in, and post.

*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAX_SIZE 100

typedef enum
{
    FALSE,
    TRUE
} Bool;


typedef struct TreeNode
{
    int val;

    TreeNode *left;     // points to left child
    TreeNode *right;    // points to right child

} TreeNode;


// ---------------------------------------------------------
// One element of our stack
//
// Every stack element stores TWO things:
//
//     node  → which tree node we are processing
//     state → which stage of that node we are in
//
// state = 1 → Preorder
// state = 2 → Inorder
// state = 3 → Postorder
// ---------------------------------------------------------
typedef struct   // It is a STACK ELEMENT that stores a tree node and its state
{
    TreeNode *node;
    int state;

} StackNode;


// ---------------------------------------------------------
// Stack
//
// arr[] → array of StackNode
// top   → tells us the top position of stack
// ---------------------------------------------------------

typedef struct
{
    StackNode arr[MAX_SIZE];  // Our MAIN stack is an array of STACK ELEMENTS(StackNode)
    int top;

} Stack;


class PreInPostOrder
{
public:

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


    // Add a tree node and its state to the stack
    // push(&s, root, 1)
    //
    // means:
    //     put root into stack
    //     with state = 1

    Bool push(Stack *s, TreeNode *node, int state)
    {
        if (isFull(*s))
        {
            return FALSE;
        }

        s->top++;
        
        //StackNode is a struct.To access its members we use dot operator.
        //StackNode x;
        //To access the members of x we use x.node and x.state
        
        s->arr[s->top].node = node; // Store the tree node
        s->arr[s->top].state = state; // Store the state of that node

        return TRUE;
    }

    // We don't need to return the popped node.
    // We don't need to delete the tree node.
    // We only decrease top.

    void pop(Stack *s)
    {
        if (!isEmpty(*s))
        {
            s->top--;
        }
    }

    // PREORDER + INORDER + POSTORDER
    // USING ONE STACK

    void preinpost(TreeNode *root)
    {
        Stack s = createStack();


        // Three vectors to store the answers
        vector<int> pre;
        vector<int> in;
        vector<int> post;


        // If tree is empty, nothing to do
        if (root == NULL)
        {
            return;
        }


        // Initially put root into stack
        //
        // State 1 means:
        // "We are seeing root for the first time"
        push(&s, root, 1);


        // Continue until stack becomes empty
        while (!isEmpty(s))
        {
            
            TreeNode *node = s.arr[s.top].node; // Get the tree node at the TOP of stack


           
            // STATE 1
            // First time we process this node
            // This is PREORDER position
            // PREORDER = ROOT -> LEFT -> RIGHT


            if (s.arr[s.top].state == 1)
            {
                // Add node to preorder
                pre.push_back(node->val);

                // Change its state:
                //
                // State 1 is completed.
                // Next time we come back to this node,
                // we need to perform INORDER.
                s.arr[s.top].state = 2;


                // Go to left child
                if (node->left != NULL)
                {
                    // New node always starts with state 1
                    push(&s, node->left, 1);
                }
            }


            // STATE 2

            // Left subtree is completed.
            //
            // This is INORDER position.
            //
            // INORDER = LEFT -> ROOT -> RIGHT
            // =================================================
            else if (s.arr[s.top].state == 2)
            {
                // Add node to inorder
                in.push_back(node->val);


                // Change state:
                //
                // State 2 is completed.
                // Next time we come back,
                // we perform POSTORDER.
                s.arr[s.top].state = 3;


                // Go to right child
                if (node->right != NULL)
                {
                    // New node starts with state 1
                    push(&s, node->right, 1);
                }
            }


            // =================================================
            // STATE 3
            // =================================================
            //
            // Both left and right subtrees are completed.
            //
            // Now this node is in POSTORDER position.
            //
            // POSTORDER = LEFT -> RIGHT -> ROOT
            // =================================================
            else
            {
                // Add node to postorder
                post.push_back(node->val);


                // We are completely finished with this node.
                // So remove it from stack.
                pop(&s);
            }
        }


        
        printf("Preorder : ");

        for (int x : pre)
        {
            printf("%d ", x);
        }


        printf("\nInorder  : ");

        for (int x : in)
        {
            printf("%d ", x);
        }


        printf("\nPostorder: ");

        for (int x : post)
        {
            printf("%d ", x);
        }
    }
};