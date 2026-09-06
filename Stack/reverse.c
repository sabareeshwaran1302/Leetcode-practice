/*
2.	Create a character array. 
Read a string from keyboard and 
print the reverse using stack.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {FALSE, TRUE} Bool;

typedef struct
{
    char val[MAX_SIZE];
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

Bool push(Stack *s,char val)
{
    if(isFull(*s))
        return FALSE;

    s->top=s->top+1;
    s->val[s->top]=val;

    return TRUE;
}

Bool pop(Stack *s,char *val)
{
    if(isEmpty(*s))
        return FALSE;

    *val=s->val[s->top];
    s->top=s->top-1;

    return TRUE;
}

char peek(Stack s)
{
    if(isEmpty(s))
        return '\0';

    return s.val[s.top];
}

int main()
{
    Stack s1;
    s1=createStack();

    char arr[MAX_SIZE];

    printf("Enter the string : ");
    scanf("%s",arr);

    int i=0;

    while(arr[i]!='\0')
    {
        push(&s1,arr[i]);
        i++;
    }

    printf("\n\nPrinting Reverse of the Given String : \n");

    char val;

    while(isEmpty(s1)!=TRUE)
    {
        pop(&s1,&val);
        printf("%c",val);
    }

    return 0;
}
