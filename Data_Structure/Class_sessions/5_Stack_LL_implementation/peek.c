#include "stack.h"

int Peek(Stack_t **top)
{
    if(*top == NULL)	//if stack is empty
    {
	return FAILURE;
    }

    return ((*top) -> data);	//returning top element
}
