#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *stk)
{
    int element;

    if(is_stack_empty(stk) == TRUE)
    {
	return FAILURE;
    }

    element = stk -> item[stk -> top];
    printf("Element popped: %d\n", element);

    (stk -> top)--;

    return SUCCESS;
}
