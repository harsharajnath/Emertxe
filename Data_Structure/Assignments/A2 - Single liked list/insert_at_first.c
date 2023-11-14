#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
    /* Creating the new node */
    Slist *new = malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if (new == NULL)
    {
	return FAILURE;
    }

    /* Fill the parts of the node */
    new->data = data;
    new->link = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
	/*If *head is empty then create the first node */
	*head = new;
	return SUCCESS;
    }
    else
    {
	/* *head is not empty then store value i.e link in the temp variable */
	Slist *temp = *head;

	/* Stroring that new link in the head inserting the element at first */
	*head = new;

	/* Creating the link to next data */
	new -> link = temp;
    }

    return SUCCESS;
}
