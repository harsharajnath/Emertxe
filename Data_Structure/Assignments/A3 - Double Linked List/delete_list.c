#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return FAILURE;
    }
    else
    {
	//create local reference pointer
	Dlist *temp = *head;

	//traversing through the list till the last node and deleting each node
	while(temp -> next != NULL)
	{
	    //updating the link
	    *head = temp -> next;

	    //deleting the node
	    free(temp);

	    //updating the link
	    temp = *head;
	}	    

	//deleting the last node
	if(temp -> next == NULL)
	{
	    //updating the link
	    *head = NULL;
	    *tail = NULL;

	    //deleting the node
	    free(temp);
	}
    }

    return SUCCESS;
}
