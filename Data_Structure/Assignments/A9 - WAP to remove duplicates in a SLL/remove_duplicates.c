#include "sll.h"

/* function to remove duplicate data's from list */
int remove_duplicates( Slist **head )
{
    /* check for list empty or not */
    if(*head == NULL)
    {
	return FAILURE;
    }


    /* if only one node present */
    if(((*head) -> link) == NULL)
    {
	return SUCCESS;
    }


    /* create local reference pointer */
    Slist *temp = *head;    //1st element
    Slist *temp_iter;       //pointer for looping through the list
    Slist *duplicate;       //stores duplicate element node address


    /* loop to compare all elements against duplicacy */
    while (temp != NULL && temp -> link != NULL)
    {
	/* updating temp_iter pointer */
	temp_iter = temp;

	/* comparing one element with rest of the elements */
	while(temp_iter -> link != NULL)
	{
	    if(temp-> data == (temp_iter -> link) -> data)      //if duplicate element found
	    {
		duplicate = temp_iter -> link;      //storing the duplicate element address to duplicate pointer

		temp_iter -> link = (temp_iter -> link) -> link;    //updating the link of temp_iter pointer

		free(duplicate);        //deallocating the memory
	    }
	    else        //if duplicate element not found
	    {
		temp_iter = temp_iter -> link;      //updating the temp_iter
	    }
	}

	/* updating the temp after each complete iteration through the list */
	temp = temp -> link;
    }

    return SUCCESS;
}
