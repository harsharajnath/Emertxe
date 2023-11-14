#include "sll.h"

int sl_delete_first(Slist **head)
{
    //check for list empty or not
    if(*head == NULL)   //if empty
    {
	return LIST_EMPTY;
    }
    else    //if not empty
    {
	Slist *temp = *head;
	*head = temp -> link;
	free(temp);     //deallocation the memory

	return SUCCESS;
    }
}
