#include "sll.h"

int insert_before(Slist **head, data_t g_data, data_t n_data)
{
    //check for list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }


    //create node
    Slist *new = malloc(sizeof(Slist));

    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }


    if (((*head) -> data) == g_data)
    {
	//updating new node data
	new -> data = n_data;

	//updating new node link
	new -> link = *head;

	*head = new;

	return SUCCESS;
    }
    else
    {
	//create local reference pointer
	Slist *temp = *head;
	Slist *temp_prev;


	//traversing through the list till last node
	while(temp != NULL)
	{
	    if(temp -> data != g_data)	//if data does not match
	    {
		temp_prev = temp;
		temp = temp -> link;	//increment the temp pointer
	    }
	    else	//if data matches
	    {

		//updating new node data
		new -> data = n_data;

		//updating new node link
		new -> link = temp;

		//updating temp link
		temp_prev -> link = new;

		return SUCCESS;
	    }
	}

	if(temp == NULL)	//when last node is reached
	{
	    return DATA_NOT_FOUND;
	}
    }
}    
