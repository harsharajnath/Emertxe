#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //if only one node present
    if((*head) -> next == NULL)    
    {
	//if data matches
	if((*head) -> data == data)
	{
	    //create local reference pointer
	    Dlist *temp = *head;

	    //updating the links
	    *head = NULL;
	    *tail = NULL;

	    //deleting the node
	    free(temp);

	    return SUCCESS;
	}
	else
	{
	    return DATA_NOT_FOUND;
	}
    }

    //create local reference pointer
    Dlist *temp = *head;
    Dlist *temp_2nd;

    //traversing through the list till last node
    while(temp != NULL)
    {
	//if data matches
	if(temp -> data == data )
	{
	    //if data matched at the 1st node
	    if(temp == *head)
	    {
		//updating the links
		*head = NULL;
		*tail = NULL;

		//deleting the node
		free(temp);

		return SUCCESS;
	    }
	    //if data matched at the last node
	    else if (temp == *tail)
	    {
		//updating the links
		temp_2nd -> next = NULL;

		//deleting the node
		free(temp);

		return SUCCESS;
	    }
	    //if data matched anywhere else
	    else
	    {
		////updating the links
		temp_2nd -> next = temp -> next;
		(temp -> next) -> prev = temp_2nd;

		//deleting the node
		free(temp);

		return SUCCESS;
	    }
	}
	else    //if data not matched
	{
	    //incrementing the temp pointers
	    temp_2nd = temp;
	    temp = temp -> next;
	}
    }

    //if temp reaches NULL and data did not matched
    if(temp == NULL)
    {
	return DATA_NOT_FOUND;
    }
}
