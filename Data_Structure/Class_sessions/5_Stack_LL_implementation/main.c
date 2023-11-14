#include "stack.h"

int main()
{
    int option, data, peek;

    /* Initiallising the top as NULL */
    Stack_t *top = NULL;

    printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Destroy Stack\n6. Exit\n");

    while (1)
    {
	/*ask user options*/
	printf("\nEnter your choice : ");
	scanf("%d", &option);

	switch (option)
	{
	    case 1:

		/* To Push the element */
		printf("Enter the element you have to insert at the first : ");
		scanf("%d", &data);
		if ((Push(&top, data)) == FAILURE)
		{
		    printf("INFO : Push operation Failure\n");
		}
		break;
	    case 2:

		/* To Pop the top of the value in the stack */
		if ((Pop(&top)) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Pop operation is successful\n");
		}
		break;
	    case 3:
		/* Printing or Dispaying the elements */
		Peep(top);
		break;
	    case 4:
		/* To find the Peek element in the stack */
		if ((peek = Peek(&top)) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Peek element is %d\n", peek);
		}
		break;
	    case 5:
		if (destroystack(&top) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Stack destroyed successfully\n");
		}
		break;
	    case 6:
		return SUCCESS;

	    default:
		printf("Enter proper choice !!\n");
		break;
	}

    }

    return SUCCESS;
}
