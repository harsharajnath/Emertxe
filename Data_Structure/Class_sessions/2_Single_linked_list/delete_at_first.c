#include "sll.h"

int delete_at_first(Slist **head)
{
    //check for list empty or not
    if(*head == NULL)		//if empty
    {
	return LIST_EMPTY;
    }
    else	//if not empty
    {
	Slist *temp = *head;

	*head = temp -> link;

	free(temp);

	return SUCCESS;
    }
}    
