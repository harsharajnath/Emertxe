#include "dll.h"

int insert_at_last(Dlist **head, Dlist **tail, data_t data)
{
    //create node
    Dlist *new = malloc(sizeof(Dlist));


    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }


    // update node parts
    new -> prev = NULL;
    new -> data = data;
    new -> next = NULL;


    //check for list empty or not
    if(*head == NULL)
    {
	*head = new;
	*tail = new;
	return SUCCESS;
    }


    //going to last node using tail pointer
    //establishing link between the last node and the new node

    (*tail) -> next = new;
    new -> prev = *tail;


    //updating the tail pointer
    *tail = new; 

    return SUCCESS;
}
