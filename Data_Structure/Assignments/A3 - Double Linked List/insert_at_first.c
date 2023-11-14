#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
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
    if(*head == NULL)		//if empty
    {
	*head = new;	//updating the head pointer
	*tail = new;	//updating the tail pointer
	return SUCCESS;
    }
    else	//if not empty
    {
	//establishing the links
	new -> next = *head;
	*head = new;
	return SUCCESS;
    }
}
