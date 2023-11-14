#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //Allocating the memory for new node
    Dlist *new = malloc(sizeof (Dlist));

    // If the node is not created the returning failure
    if (!new)
    {
	return FAILURE;
    }
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;

    // If the list is empty then inserting the node as first node
    if (!*head && !*tail)
    {	
	*head = *tail = new;
	return SUCCESS;
    }
    new -> prev = *tail;
    (*tail) -> next = new;
    *tail = new;
    return SUCCESS;
}
