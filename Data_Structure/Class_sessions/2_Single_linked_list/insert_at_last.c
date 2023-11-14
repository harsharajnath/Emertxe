#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
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
    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }


    //create local reference pointer
    Slist *temp = *head;


    //traversing through the list till last node
    while(temp -> link != NULL)
    {
	temp = temp -> link;
    }


    //when last node is reached, establishing link between
    //the last node and the new node
    temp -> link = new;
    return SUCCESS;

}    
