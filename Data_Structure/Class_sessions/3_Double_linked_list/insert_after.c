#include "dll.h"

int insert_after(Dlist **head, Dlist **tail, data_t g_data, data_t n_data)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }
    //create local reference pointer
    Dlist *temp = *head;


    //traversing through the list till last node
    while(temp != NULL)
    {
	if(temp -> data != g_data)	//if data does not match
	{
	    temp = temp -> next;	//increment the temp pointer
	}
	else	//if data matches
	{
	    //create node
	    Dlist *new = malloc(sizeof(Dlist));

	    //error check
	    //if new node pointer is pointing to some address or NULL
	    if(new == NULL)
	    {
		return FAILURE;
	    }

	    //updating new node data
	    new -> data = n_data;

	    //updating new node links
	    new -> prev = temp;
	    new -> next = temp -> next;

	    //updating the new node's next node's previous link
	    /*REMEMBER: this has to be done before updating the temp link,
	    		or else we will lose the address*/
	    if(temp != *tail)	//if temp is not the last node
	    {
	    	(temp -> next) -> prev = new;
	    }
	    else	//if temp is the last node
	    {
		*tail = new;
	    }
	    
	    //updating temp link
	    temp -> next = new;

	    return SUCCESS;
	}

    }

    return DATA_NOT_FOUND;
}
