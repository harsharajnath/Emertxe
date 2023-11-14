#include "stack.h"

//function to pop element from the stack
int Pop(Stack_t **top)
{
    //check for stack empty or not
    if(*top == NULL)        //if empty
    {
	return FAILURE;
    }
    else        //if not empty
    {
	Stack_t *temp = *top;   //creating local reference pointer
	*top = temp -> link;    //updating the top
	free(temp);     //deallocation the memory

	return SUCCESS;
    }
}
