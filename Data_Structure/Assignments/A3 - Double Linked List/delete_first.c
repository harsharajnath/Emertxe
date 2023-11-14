#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)		//if empty
    {
	return FAILURE;
    }

    if((*head) -> next == NULL)    //if only one node present
    {
	//create local reference pointer
	Dlist *temp = *head;

	//updating the links
	*head = NULL;
	*tail = NULL;

	//deleting the node
	free(temp);
    }
    else	//more than one node present
    {
	//create local reference pointer
	Dlist *temp = *head;

	//updating the link
	*head = temp -> next;

	//deleting the node
	free(temp);

	//updating the link
	(*head) -> prev = NULL;
    }

    return SUCCESS;
}
