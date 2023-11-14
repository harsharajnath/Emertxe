#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    int pos = 1;

    //create node
    Slist *new = malloc(sizeof(Slist));

    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }

    // update node parts
    new -> data = data;
    new -> link = NULL;


    //check for list empty or not
    if(*head == NULL)       //if list empty
    {
	if(n > 1)   //check if given position is greater than 1
	{
	    return LIST_EMPTY;
	}
	else    //if given position  is 1
	{
	    //establishing the links
	    *head = new;
	    new -> link = NULL;       //updating new node link to NULL
	    return SUCCESS;
	}
    }

    //create local reference pointer
    Slist *temp = *head;
    Slist *temp_prev;

    //traversing through the list till last node
    while(temp -> link != NULL)
    {
	if(pos == n && temp == *head)       //if data to be inserted at 1st position
	{
	    //establishing the links
	    new -> link = *head;
	    *head = new;
	    return SUCCESS;
	}
	else
	{
	    if(pos == n)        //if position matches between 2nd node and 2nd last node
	    {
		//establishing the links
		new -> link = temp_prev -> link;
		temp_prev -> link = new;

		return SUCCESS;
	    }
	    else        //if position does not matches
	    {
		pos++;      //incrementing the position
		temp_prev = temp;       //storing the previous node address
		temp = temp -> link;        //updating the temp pointer
	    }
	}
    }

    if(temp -> link == NULL)    //last node
    {
	if(pos == n)        //if position matches
	{
	    //establishing the links
	    new -> link = *head;
	    *head = new;

	    return SUCCESS;
	}
	else if ((pos + 1) == n)        //if position given is at NULL
	{
	    //establishing the links
	    temp -> link = new;
	    new -> link = NULL;

	    return SUCCESS;
	}
    }

    return POSITION_NOT_FOUND;
}
