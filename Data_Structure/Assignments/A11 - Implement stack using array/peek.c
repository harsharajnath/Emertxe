#include "stack.h"

int is_stack_empty(Stack_t *);

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
    if(is_stack_empty(s) == TRUE)        //function call to is_stack_empty()
    {
	return FAILURE;
    }

    return s -> stack[s -> top];    //returning the top element
}
