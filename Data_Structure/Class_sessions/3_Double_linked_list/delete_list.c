#include "dll.h"

int delete_list(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }
    else
    {
	//create local reference pointer
	Dlist *temp = *head;

	//traversing through the list till last node
	while(temp -> next != NULL)
	{
	    *head = temp -> next;
	    free(temp);
	    temp = *head;
	}	    

	if(temp -> next == NULL)
	{
	    *head = NULL;
	    *tail = NULL;
	    free(temp);
	}
    }
}
