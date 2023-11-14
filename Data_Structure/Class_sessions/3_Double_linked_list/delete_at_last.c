#include "dll.h"

int delete_at_last(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //if only one node present
    if(((*head) -> next) == NULL)
    {
	*head = NULL;
	*tail = NULL;
	return SUCCESS;
    }

    //create local reference pointer
    Dlist *temp = *head;
    Dlist *temp_2nd;


    //traversing through the list till last node
    while(temp -> next != NULL)
    {
	temp_2nd = temp;
	temp = temp -> next;
    }

    if(temp -> next == NULL)
    {
	temp_2nd -> next = NULL;
	free(temp);
    }
}
