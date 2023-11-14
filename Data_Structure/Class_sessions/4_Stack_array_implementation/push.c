#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *stk, int element)
{
    if(is_stack_full(stk) == TRUE) 
    {
	return FAILURE;
    }

    ++stk -> top;	//stk = stk + 1 -> top
    
    stk -> item[stk -> top] = element;		//inserting at top

    return SUCCESS;
}
