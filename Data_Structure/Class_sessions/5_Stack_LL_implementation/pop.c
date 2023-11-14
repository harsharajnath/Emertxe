#include "stack.h"

int Pop(Stack_t **top)
{
    int element;

    //check for stack empty or not
    if(*top == NULL)		//if empty
    {
	return FAILURE;
    }
    else	//if not empty
    {
	Stack_t *temp = *top;	//creating local reference pointer

	element = (*top) -> data;
	printf("Element popped: %d\n", element);

	*top = temp -> link;	//updating the top

	free(temp);	//deallocating the memory

	return SUCCESS;
    }	
}
