#include "sll.h"

int delete_list(Slist **head)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }
    else
    {
	//create local reference pointer
	Slist *temp = *head;

	//traversing through the list till last node
	while(temp -> link != NULL)
	{
	    *head = temp -> link;
	    free(temp);
	    temp = *head;
	}	    

	if(temp -> link == NULL)
	{
	    *head = NULL;
	    free(temp);
	}
    }
}
