#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //create node
    Dlist *new = malloc(sizeof(Dlist));

    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }

    if (((*head) -> data) == gdata)
    {
	//updating new node data
	new -> data = ndata;

	//updating new node link
	new -> prev = NULL;
	new -> next = *head;
	*head = new;

	return SUCCESS;
    }
    else
    {
	//create local reference pointer
	Dlist *temp = *head;
	Dlist *temp_2nd;

	//traversing through the list till last node
	while(temp != NULL)
	{
	    if(temp -> data != gdata)	//if data does not match
	    {
		temp_2nd = temp;
		temp = temp -> next;	//increment the temp pointer
	    }
	    else	//if data matches
	    {
		//updating new node data
		new -> data = ndata;

		//updating new node link
		new -> next = temp;
		new -> prev = temp_2nd;

		//updating temp link
		temp -> prev = new;
		temp_2nd -> next = new;

		return SUCCESS;
	    }
	}

	if(temp == NULL)	//when last node is reached
	{
	    return DATA_NOT_FOUND;
	}
    }
}
