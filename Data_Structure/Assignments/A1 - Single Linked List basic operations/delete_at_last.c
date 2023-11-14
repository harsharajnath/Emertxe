#include "sll.h"

int sl_delete_last(Slist **head)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }


    //if only one node present
    if(((*head) -> link) == NULL)
    {
	*head = NULL;
	return SUCCESS;
    }


    //create local reference pointer
    Slist *temp = *head;
    Slist *temp_prev;


    //traversing through the list till last node
    while(temp -> link != NULL)
    {
	temp_prev = temp;
	temp = temp -> link;
    }

    if(temp -> link == NULL)
    {
	temp_prev -> link = NULL;
	free(temp);     //deallocation the memory
    }
}
