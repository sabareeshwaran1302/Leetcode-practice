/*
Find whether given list of values 
is in increasing order or not.


*/
#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node * next;
} NODE;

void display(NODE *l)
{
    while(l)
    {
        printf("%5d",l->data);
        l = l->next;
    }
}

NODE *makeNode(int data)
{
    NODE *temp = (NODE *) malloc(sizeof(NODE));
    temp->data = data;
    temp->next=NULL;
    return temp;
}

NODE *insertTail(NODE *l, int data)
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

int ascending(NODE *l)
{
    if(l==NULL)
    {
        return 1;
    }

    while(l->next)
    {
        int temp=l->data;
        l=l->next;

        if(l->data<temp)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    NODE *l1=NULL;

    int n,data,i=1;

    printf("Enter number of elements : ");
    scanf("%d",&n);

    while(i<=n)
    {
        printf("Enter %d th element : ",i);
        scanf("%d",&data);

        l1=insertTail(l1,data);

        i++;
    }

    printf("\nList 1 : ");
    display(l1);

    printf("\n\n");

    int res=ascending(l1);

    if(res)
    {
        printf("It is in Ascending order\n\n");
    }
    else
    {
        printf("Not in Ascending Order\n\n");
    }

    return 1;
}