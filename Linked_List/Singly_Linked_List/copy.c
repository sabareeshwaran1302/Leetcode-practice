
/*
Create a copy of the 
given linked list

*/
NODE *copy(NODE *l1)
{
    NODE *l2=NULL;

    while(l1)
    {
        l2=insertTail(l2,l1->data);
        l1=l1->next;
    }

    return l2;
}