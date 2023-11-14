#include "sll.h"    

/* sort() will sort nodes of the list in ascending order */ 
int sort(Slist **head)
{
    /* check for list empty or not */
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    /* declaring a flag which will keep track of whether any swapping happened */
    int swapped;

    /* repeat from beginning till no swapping is required */
    do
    {
	/* resetting the flag */
	swapped = 0;


	/* create local reference pointer */
	Slist *prev = NULL;     //prev pointer pointing to NULL
	Slist *current = *head;     //current pointer pointer to 1st element
	Slist *next = (*head) -> link;      //next pointer pointing to 2nd element


	/* iterating till the last node */
	while(next != NULL)
	{
	    /* if current data is greater than next data */
	    if(current -> data > next -> data)
	    {
		if(prev != NULL)    /* if not the 1st node */
		{
		    /* create local reference pointer */
		    Slist *temp;

		    /* swapping the links */
		    temp = next -> link;    
		    prev -> link = next;
		    next -> link = current;
		    current -> link = temp;
		}
		else    /* if 1st node */
		{
		    /* create local reference pointer */
		    Slist *temp;

		    /* swapping the links */
		    temp = next -> link;
		    *head = next;
		    next -> link = current;
		    current -> link = temp;
		}

		/* incrementing the flag indicating swapping has happened */
		swapped++;

		/* updating the node positions accordingly after swapping happened */
		prev = next;
		next = current -> link;
	    }

	    /* if current data is not greater than next data */
	    else
	    {
		/* increment all the pointers by one position */
		prev = current;
		current = next;
		next = next -> link;
	    }
	}

    } while(swapped > 0);   /* swapped flag = 0 indicates no more swapping requred, all elements are sorted */

    return SUCCESS;
}
