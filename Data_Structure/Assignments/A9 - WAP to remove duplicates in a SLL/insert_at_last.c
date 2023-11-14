#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    /* create new node */
    Slist *new = malloc(sizeof(Slist));
    if (!new)
    {
	return FAILURE;
    }

    /* if new node created, update data + link */
    new->data = data;
    new->link = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
	/* add new node to first position */
	*head = new;
	return SUCCESS;
    }

    /* else */
    /* temp points to first node */
    Slist *temp = *head;

    /* traverse to next node check next node is present or not */
    while (temp->link != NULL)
    {
	temp = temp->link;
    }

    /* establish the link between last and new node*/
    temp->link = new;

    return SUCCESS;
}
