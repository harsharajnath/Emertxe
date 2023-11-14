#include "dll.h"

int delete_at_first(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)		//if empty
    {
	return LIST_EMPTY;
    }
    
    if((*head) -> next == NULL)    //if only one node
    {
	//free(head);

	*head = NULL;
	*tail = NULL;

	return SUCCESS;
    }
    else	//more than one node
    {
	Dlist *temp = *head;
	*head = temp -> next;
	free(temp);
	(*head) -> prev = NULL;

	return SUCCESS;
    }
}    
