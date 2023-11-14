#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    //checking for list empty or not
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

    if(((*head) -> data) == g_data)     //if data present at first node
    {
	//update new node data
	new -> data = ndata;

	//updating new node link
	new -> link = *head;

	//updating head pointer
	*head = new;

	return SUCCESS;
    }
    else        //traverse the list
    {
	//create local reference pointer
	Slist *temp = *head;
	Slist *temp_prev;

	//traversing through the list till last node
	while(temp != NULL)
	{
	    if(temp -> data != g_data)      //if data does not matches
	    {
		temp_prev = temp;       //storing previous node address
		temp = temp -> link;    //incrementing the temp pointer
	    }
	    else        //if data matches
	    {
		//establishing the links
		new -> data = ndata;
		new -> link = temp;
		temp_prev -> link = new;

		return SUCCESS;
	    }
	}

	if(temp == NULL)        //when last node is reached
	{
	    return DATA_NOT_FOUND;
	}
    }
}
