#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    //check if list empty or not
    if(head == NULL)
    {
	return LIST_EMPTY;
    }

    //create local reference pointer
    Slist *fast = head;		//move two nodes at a time
    Slist *slow = head;		//moves one node at a time

    //if fast pointer becomes NULL, this means loop not present


    //traversing till the end of list
    while( slow -> link != NULL && fast != NULL)
    {
	fast = (fast -> link) -> link;		//moving two nodes ahead
	slow = slow -> link;		//moving one node ahead

	if(fast == slow)    //loop is present
	{
	    return SUCCESS;
	}
    }

    //else loop is not present
    return LOOP_NOT_FOUND;
}
