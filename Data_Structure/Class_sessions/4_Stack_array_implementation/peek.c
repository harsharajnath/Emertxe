#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *stk)
{
    if(is_stack_empty(stk) == TRUE)
    {
	return FAILURE;
    }

    return stk -> item[stk -> top];
}
