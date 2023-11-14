#include "stack.h"

int is_stack_empty(Stack_t *);

/* Function for Poping the element */
int Pop(Stack_t *s)
{	
    if(is_stack_empty(s) == TRUE)        //function call to is_stack_empty()
    {
	return FAILURE;
    }

    (s -> top)--;   //decrementing the top

    return SUCCESS;
}

int is_stack_empty(Stack_t *stk)     //function to check if stack is empty
{
    if(stk -> top == -1)        //top = -1
    {
	return TRUE;
    }
    else
    {
	return FALSE;
    }
}

