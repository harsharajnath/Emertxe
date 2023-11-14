#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    //check if list empty or not
    if(*head == NULL)
    {
	return LIST_EMPTY;
    }

    //create local referece pointer
    Slist *temp = *head;

    //travering through the list till last node
    while(temp != NULL)
    {
	if(temp -> data != g_data)      //if data does not matches
	{
	    temp = temp -> link;        //increment the temp pointer
	}
	else        //if data matches
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
	    new -> data = ndata;

	    //updating new node link
	    new -> link = temp -> link;

	    //updating temp link
	    temp -> link = new;

	    return SUCCESS;
	}
    }

    if(temp == NULL)    //when last node is reached
    {
	return DATA_NOT_FOUND;   
    }
}
