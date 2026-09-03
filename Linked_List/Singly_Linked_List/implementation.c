/*
SINGLY LINKED LIST

1.MAKE NODE AND DISPLAY
2.INSERT AT HEAD
3.INSERT AT TAIL
4.DELETE AT HEAD
5.DELETE AT TAIL
6.INSERT AT GIVEN POSITION
7.DELETE AT GIVEN POSITION

*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *makeNode(int data)
{
    NODE *temp=(NODE *)malloc(sizeof(NODE));

    temp->data=data;
    temp->next=NULL;

    return temp;
}

void display(NODE *l)
{
    if(l==NULL)
    {
        printf("List is Empty.");
        return;
    }

    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}

NODE *insertHead(NODE *l,int data)
{
    NODE *temp=makeNode(data);

    temp->next=l;

    return temp;
}

NODE *insertTail(NODE *l,int data)
{
    NODE *temp;
    NODE *p=makeNode(data);

    if(l==NULL)
    {
        return p;
    }

    temp=l;

    while(temp->next)
    {
        temp=temp->next;
    }

    temp->next=p;

    return l;
}

NODE *deleteHead(NODE *l)
{
    if(l==NULL)
    {
        printf("List is empty.");
        return l;
    }

    NODE *temp=l;

    l=l->next;

    free(temp);

    return l;
}

NODE *deleteTail(NODE *l)
{
    if(l==NULL)
    {
        printf("List is empty.");
        return l;
    }

    NODE *p=l;

    if(p->next==NULL) // SINGLE NODE CASE
    {
        free(p);
        return NULL;
    }

    while(p->next->next)
    {
        p=p->next;
    }

    free(p->next);
    p->next=NULL;

    return l;
}

NODE *insertPos(NODE *l,int data,int pos)
{
    if(pos==1)
    {
        l=insertHead(l,data);
        return l;
    }

    NODE *p,*q;
    NODE *temp=makeNode(data);

    int i=1;
 
    p=l;

    while(p!=NULL && i<pos-1)
    {
        p=p->next;
        i++;
    }

    if(p==NULL)
    {
        printf("Invalid Position.");
        free(temp);
        return l;
    }

    q=p->next;

    p->next=temp;
    temp->next=q;

    return l;
}

NODE *deletePos(NODE *l,int pos)
{
    if(pos==1)
    {
        l=deleteHead(l);
        return l;
    }

    NODE *temp,*p;

    temp=l;

    int i=1;

    while(i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    if(temp==NULL || temp->next==NULL)
    {
        printf("Invalid Position.");
        return l;
    }

    p=temp->next;

    temp->next=p->next;

    free(p);

    return l;
}

int main()
{
    NODE *l=NULL;

    int n,i=1,data;

    printf("\nEnter number of elements : \n");
    scanf("%d",&n);

    while(i<=n)
    {
        printf("Enter %d th Element : ",i);
        scanf("%d",&data);

        l=insertTail(l,data);

        i++;
    }

    printf("List after inserting at Tail : ");
    display(l);

    printf("\nEnter Element to insert at HEAD : ");
    scanf("%d",&data);

    l=insertHead(l,data);

    printf("List after inserting at HEAD : ");
    display(l);

    printf("\nEnter Element to insert at TAIL : ");
    scanf("%d",&data);

    l=insertTail(l,data);

    printf("List after inserting at TAIL : ");
    display(l);

    l=deleteHead(l);

    printf("\nList after DELETING at HEAD : ");
    display(l);

    l=deleteTail(l);

    printf("\nList after DELETING at TAIL : ");
    display(l);

    int pos;

    printf("\nEnter Position to INSERT : ");
    scanf("%d",&pos);

    printf("Enter ELEMENT to INSERT : ");
    scanf("%d",&data);

    l=insertPos(l,data,pos);

    printf("List after INSERTING at GIVEN POSITION : ");
    display(l);

    printf("\nEnter Position to DELETE : ");
    scanf("%d",&pos);

    l=deletePos(l,pos);

    printf("List after DELETING at GIVEN POSITION : ");
    display(l);

    return 0;
}