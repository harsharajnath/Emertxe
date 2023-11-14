#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return FAILURE;
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

    //deleting the last node
    if(temp -> next == NULL)
    {
	temp_2nd -> next = NULL;
	free(temp);
    }

    return SUCCESS;
}
