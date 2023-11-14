#include "stack.h"

//function to see the top element
int Peek(Stack_t **top)
{
    if(*top == NULL)    //if stack is empty
    {
	return FAILURE;
    }

    return ((*top) -> data);    //returning the top element
}
