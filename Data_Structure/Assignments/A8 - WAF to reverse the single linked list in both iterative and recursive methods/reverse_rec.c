#include "sll.h"

/* Function to reverse the given single linked list (recursive method) */
int reverse_recursive(Slist ** head)
{
    /* check for list empty or not */
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    /* create local reference pointer */
    Slist *previous = NULL;     //prev pointer pointing to NULL
    Slist *current = *head;     //current pointer pointer to 1st element
    Slist *next = (*head) -> link;      //next pointer pointing to 2nd element

    /* function call for swap() */
    swap(head, previous, current, next);

    return SUCCESS;
}

/* Function for swapping the node links */
int swap(Slist **head, Slist *previous, Slist *current, Slist *next)
{
    /* base condition */
    if( next == NULL)
    {
	/* updating the links for the last node */
	current -> link = previous;

	/* updating the head pointer */
	*head = current;

	return SUCCESS;
    }

    /* updating the link */
    current -> link = previous;

    /* increment all the pointers by one position */
    previous = current;
    current = next;
    next = next -> link;

    /* recursive function call */
    swap(head, previous, current, next);
}

