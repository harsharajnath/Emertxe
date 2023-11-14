#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{ 
    //create node
    Slist *new = malloc(sizeof(Slist));

    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }

    //update node parts
    new -> data = data;
    new -> link = NULL;

    //check for list empty or not
    if(*head == NULL)
    {
	//updating the head with new node address
	*head = new;
	return SUCCESS;
    }

    //if only one node present
    if((*head) -> link == NULL)
    {
	//if 1st node data is greater than the given data
	if((*head) -> data > data)
	{
	    //updating the links
	    new -> link = *head;
	    *head = new;
	}
	//if 1st node data is less than the given data
	else
	{
	    //updating the link
	    (*head) -> link = new;
	}

	return SUCCESS;
    }


    //create local reference pointer
    Slist *temp = *head;
    Slist *temp_prev;

    //traversing through the list till last node
    while(temp != NULL)
    {
	//if temp node data is greater than the given data
	if((temp -> data) > data)
	{
	    //if temp is at 1st node itself
	    if(temp == *head)
	    {
		//updating the links
		new -> link = *head;
		*head = new;
		return SUCCESS;
	    }

	    //updating the links
	    new -> link = temp;
	    temp_prev -> link = new;
	    return SUCCESS;
	}
	//if temp node data is less than the given data
	else 
	{
	    temp_prev = temp;       //storing previous node address
	    temp = temp -> link;    //incrementing the temp pointer
	}
    }

    // when temp is NULL and data not inserted yet
    if(temp == NULL)
    {
	/* update the temp_prev link with the new node, so that
	   the new node become the last node */
	temp_prev -> link = new;
	return SUCCESS;
    }
}
