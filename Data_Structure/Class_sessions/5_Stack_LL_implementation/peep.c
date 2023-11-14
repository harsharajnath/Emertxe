#include "stack.h"

int Peep(Stack_t *top)
{
    /* Checking the stack is empty or not */
    if (top == NULL)
    {
	printf("INFO : Stack is empty\n");
	return FAILURE;
    }

    /* Storing the value in top for traversing */
    Stack_t *temp = top;
    
    printf("Top -> ");	
    while (temp)		
    {
	/* Printing the value from stack */
	printf("%d -> ", temp -> data);

	/* Traversing to next node */
	temp = temp -> link;
    }

    printf("NULL\n");
    return SUCCESS;
}
