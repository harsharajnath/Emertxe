#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //creating local reference pointer
    Slist *temp = *head;
    Slist *temp_prev;


    if(temp -> link == NULL)    //if only one node present
    {
	if(temp -> data == data)        //if data matches
	{
	    *head = NULL;       //updating head pointer
	    free(temp);         //deallocating the memory
	    return SUCCESS;
	}
    }

    //traversing through the list till last node
    while(temp -> link != NULL)
    {
	if(temp -> data == data && temp == *head)       //if data matched at 1st node
	{
	    *head = temp -> link;       //updating head pointer
	    free(temp);         //deallocating the memory
	    return SUCCESS;
	}
	else
	{
	    if(temp -> data == data)        //if data matches between 2nd node and 2nd last node
	    {
		temp_prev -> link = temp -> link;       //updating the links
		free(temp);         //deallocating the memory
		return SUCCESS;
	    }
	    else        //if data does not matches
	    {
		temp_prev = temp;       //storing the previous node address
		temp = temp -> link;        //updating the temp pointer
	    }
	}
    }

    if(temp -> link == NULL)    //last node
    {
	if(temp -> data == data)        //if data matches
	{
	    temp_prev -> link = NULL;       //updating previous node link to NULL
	    free(temp);         //deallocating the memory
	    return SUCCESS;
	}
    }

    return DATA_NOT_FOUND;
}
