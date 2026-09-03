/*

Check whether 2 linked lists are 
same or not.

*/
int same(NODE *l1,NODE *l2)
{
    while(l1 && l2)
    {
        if(l1->data != l2->data)
        {
            return 0;
        }

        l1=l1->next;
        l2=l2->next;
    }

    if(l1==NULL && l2==NULL)
        return 1;

    return 0;
}
