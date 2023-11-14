#include "stack.h"

int is_stack_full(Stack_t *);

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
    if(is_stack_full(s) == TRUE)        //function call to is_stack_full()
    {
	return FAILURE;
    }

    ++s -> top;     //s = s + 1 -> top

    s -> stack[s -> top] = element;     //inserting at top

    return SUCCESS;
}

int is_stack_full(Stack_t *stk)     //function to check if stack is full
{
    if(stk -> top == (stk -> capacity) - 1)     //top = size - 1
    {
	return TRUE;
    }
    else
    {
	return FALSE;
    }
}
