/*
Concatenate two lists l1 and l2 
in a new list l3.
*/
NODE *concatenate(NODE *l1,NODE *l2)
{
    NODE *l3=NULL;

    while(l1)
    {
        l3=insertTail(l3,l1->data);
        l1=l1->next;
    }

    while(l2)
    {
        l3=insertTail(l3,l2->data);
        l2=l2->next;
    }

    return l3;
}
