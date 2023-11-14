#include "stack.h"

/* Function for print the data's in the stack */
void Peep(Stack_t stk)
{
    /* Checking the Stack is empty or not */
    if (stk.top == -1)
    {
	printf("INFO : Stack is empty\n");
    }
    else
    {
	/* Declaring the temp for store the top value to print the values in the Stack*/
	printf("Top -> ");
	while (stk.top > -1)
	{
	    printf("%d ", stk.item[(stk.top)--]);
	}
	printf("\n");
    }
}
