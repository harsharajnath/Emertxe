#include "stack.h"

int is_stack_full(Stack_t *stk)
{
    if(stk -> top == (stk -> capacity) - 1)
    {
	return TRUE;
    }
    else
    {
	return FALSE;
    }
}
