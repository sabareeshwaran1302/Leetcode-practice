/*
BINARY SEARCH TREE IMPLEMENTATIONS

1. Create a binary search tree.
2. Insert a node in the binary search tree.
3. Search a node in the binary search tree.
4. Count the number of nodes in the binary search tree.
5. Count the number of leaf nodes in the binary search tree.
6. Find the height of the binary search tree.
7. Find the minimum and maximum value in the binary search tree.
8. Delete a node in the binary search tree.
9. Display the binary search tree in inorder, preorder and postorder traversals.

*/
#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;

BT *makeNode(int data)
{
    BT *t=new BT;

    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}

void inOrder(BT *t)
{
    if(t)
    {
        inOrder(t->left);
        cout<<t->data<<" ";
        inOrder(t->right);
    }
}

void preOrder(BT *t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(BT *t)
{
    if(t)
    {
        postOrder(t->left);
        postOrder(t->right);
        cout<<t->data<<" ";
    }
}

BT *insert(BT *t,int data)
{
    if(!t)
        return makeNode(data);

    if(t->data>data)
        t->left=insert(t->left,data);

    else if(t->data<data)
        t->right=insert(t->right,data);

    return t;
}

int search(BT *t,int data)
{
    if(!t)
        return 0;

    if(t->data==data)
        return 1;

    if(t->data>data)
        return search(t->left,data);

    return search(t->right,data);
}

int count(BT *t)
{
    if(!t)
        return 0;

    return 1+count(t->left)+count(t->right);
}

int countLeaf(BT *t)
{
    if(!t)
        return 0;

    if(!t->left && !t->right)
        return 1;

    return countLeaf(t->left)+countLeaf(t->right);
}

int height(BT *t)
{
    if(!t)
        return 0;

    int l=height(t->left);
    int r=height(t->right);

    if(l>r)
        return l+1;

    return r+1;
}

int minimum(BT *t)
{
    if(!t)
        return -9999;

    while(t->left)
        t=t->left;

    return t->data;
}

int maximum(BT *t)
{
    if(!t)
        return -9999;

    while(t->right)
        t=t->right;

    return t->data;
}

BT *findMin(BT *t)
{
    while(t->left)
        t=t->left;

    return t;
}

BT *deleteNode(BT *t,int data)
{
    if(!t)
        return NULL;

    if(data<t->data)
    {
        t->left=deleteNode(t->left,data);
    }
    else if(data>t->data)
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
            BT *temp=t->right;
            delete t;
            return temp;
        }

        /* Only left child */
        if(!t->right)
        {
            BT *temp=t->left;
            delete t;
            return temp;
        }

        /* Two children */
        BT *temp=findMin(t->right);

        t->data=temp->data;

        t->right=deleteNode(t->right,temp->data);
    }

    return t;
}

int main()
{
    BT *t=NULL;
    int n,data;

    cout<<"Enter Number of Elements : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" Element : ";
        cin>>data;

        t=insert(t,data);
    }

    cout<<"\nInorder : ";
    inOrder(t);

    cout<<"\nPreorder : ";
    preOrder(t);

    cout<<"\nPostorder : ";
    postOrder(t);

    cout<<"\n\nNumber of Nodes : "<<count(t);

    cout<<"\nNumber of Leaf Nodes : "<<countLeaf(t);

    cout<<"\nHeight : "<<height(t);

    cout<<"\nMinimum : "<<minimum(t);

    cout<<"\nMaximum : "<<maximum(t);

    cout<<"\n\nEnter Element to Search : ";
    cin>>data;

    if(search(t,data))
        cout<<"Element Found";
    else
        cout<<"Element Not Found";

    cout<<"\n\nEnter Element to Delete : ";
    cin>>data;

    if(search(t,data))
    {
        t=deleteNode(t,data);

        cout<<"Inorder after Deletion : ";
        inOrder(t);
    }
    else
    {
        cout<<"Element Not Found";
    }

    return 0;
}