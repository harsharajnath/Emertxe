#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    /* check for lists empty or not */
    if(*head1 == NULL && *head2 == NULL)
    {
	return LIST_EMPTY;
    }

    /* if list1 is empty and list2 is non empty */
    if(*head1 == NULL && *head2 != NULL)
    {
	*head1 = *head2;
	sort(head1);
	return SUCCESS;
    }

    /* if list1 is non empty and list2 is empty */
    if(*head1 != NULL && *head2 == NULL)
    {
	sort(head1);
	return SUCCESS;
    }

    /* if both lists are non empty */
    if(*head1 != NULL && *head2 != NULL)
    {
	/* create local reference pointer */
	Slist *temp = *head1;

	/* traversing till the last node of 1st list */
	while( temp -> link != NULL)
	{
	    temp = temp -> link;
	}

	/* updating the link of last node of the 1st list with the head pointer of 2nd list */
	temp -> link = *head2;

	/* function call for sort() */
	sort(head1);

	return SUCCESS;
    }
}
