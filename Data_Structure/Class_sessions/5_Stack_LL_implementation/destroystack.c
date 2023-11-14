#include "stack.h"

int destroystack(Stack_t **top)
{
    if(*top == NULL)	//if stack is empty
    {
	return FAILURE;
    }
    else
    {
	//creating local reference pointer
	Stack_t *temp = *top;
	Stack_t *next;

	while (temp != NULL)
	{
	    next = temp->link;
	    free(temp);
	    temp = next;
	}

	*top = NULL;
    }
}
