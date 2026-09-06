/*
Implementation of Stack Data Structure using Array in C
1. Create Stack
2. Push
3. Pop
4. Peek

Generate n random integers and 
push the odd numbers into stack1 
and even numbers into stack2.
Print stack1 and stack2 by 
copying out the entire structure.

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {FALSE, TRUE} Bool;

typedef struct
{
    int val[MAX_SIZE];
    int top;
} Stack;

Stack createStack()
{
    Stack s;
    s.top=0;
    return s;
}

Bool isEmpty(Stack s)
{
    return s.top==0;
}

Bool isFull(Stack s)
{
    return s.top==MAX_SIZE-1;
}

Bool push(Stack *s,int val)
{
    if(isFull(*s))
    {
        return FALSE;
    }

    s->top=s->top+1;
    s->val[s->top]=val;

    return TRUE;
}


Bool pop(Stack *s,int *val)
{
    if(isEmpty(*s))
    {
        return FALSE;
    }

    *val=s->val[s->top];
    s->top=s->top-1;

    return TRUE;
}

int peek(Stack s)
{
    if(isEmpty(s))
    {
        return -9999;
    }

    return s.val[s.top];
}

int main()
{
    Stack s1;
    Stack s2;

    s1=createStack();
    s2=createStack();

    int size;
    int n;

    printf("Enter Number of Elements to Generate : ");
    scanf("%d",&size);

    for(int i=0;i<size;i++)
    {
        n=rand()%100;

        if(n%2==0)
        {
            if(push(&s1,n)==FALSE)
            {
                printf("Stack Overflow\n");
            }
        }
        else
        {
            if(push(&s2,n)==FALSE)
            {
                printf("Stack Overflow\n");
            }
        }
    }

    int num1;

    printf("\n\nPrinting Even Elements : \n");

    while(isEmpty(s1)!=TRUE)
    {
        pop(&s1,&num1);
        printf("%d\t",num1);
    }

    int num2;

    printf("\n\nPrinting Odd Elements : \n");

    while(isEmpty(s2)!=TRUE)
    {
        pop(&s2,&num2);
        printf("%d\t",num2);
    }

    return 0;
}
