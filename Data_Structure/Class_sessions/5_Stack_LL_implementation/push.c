#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    //create node
    Stack_t *new = malloc(sizeof(Stack_t));


    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }


    // update node parts
    new -> data = data;
    new -> link = NULL;


    //check for stack empty or not
    if(*top == NULL)		//if empty
    {
	*top = new;
	return SUCCESS;
    }
    else	//if not empty
    {
	new -> link = *top;
	*top = new;
	return SUCCESS;
    }
}
