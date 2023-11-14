#include "sll.h"

int insert_at_first(Slist **head, data_t data)
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
    if(*head == NULL)   //if empty
    {
	*head = new;
	return SUCCESS;
    }
    else    //if not empty
    {
	//establishing the link
	new -> link = *head;
	*head = new;
	return SUCCESS;
    }
}
