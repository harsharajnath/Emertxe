#include "sll.h"

int insert_after(Slist **head, data_t g_data, data_t n_data)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }


    //create local reference pointer
    Slist *temp = *head;


    //traversing through the list till last node
    while(temp != NULL)
    {
	if(temp -> data != g_data)	//if data does not match
	{
	    temp = temp -> link;	//increment the temp pointer
	}
	else	//if data matches
	{
	    //create node
	    Slist *new = malloc(sizeof(Slist));

	    //error check
	    //if new node pointer is pointing to some address or NULL
	    if(new == NULL)
	    {
		return FAILURE;
	    }

	    //updating new node data
	    new -> data = n_data;

	    //updating new node link
	    new -> link = temp -> link;

	    //updating temp link
	    temp -> link = new;

	    return SUCCESS;
	}
    }

    if(temp == NULL)	//when last node is reached
    {
	return DATA_NOT_FOUND;
    }
}    
