#include "sll.h"

/* Function to reverse the given single linked list (iterative method) */
int reverse_iter(Slist **head) 
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


    /* looping till the last node */
    while(next != NULL)
    {
	/* updating the link */
	current -> link = previous;

	/* increment all the pointers by one position */
	previous = current;
	current = next;
	next = next -> link;
    }

    /* updating the links for the last node */
    current -> link = previous;

    /* updating the head pointer */
    *head = current;

    return SUCCESS;
}
