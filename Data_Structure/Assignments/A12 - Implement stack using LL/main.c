/*


Name: Harsharaj Nath
Date of Submission: 06-11-22
Description: Implement stack using LL

Implement the stack linked list:
1.push(stack, data)
2.pop(stack)
3.peek(stack)
4.peep(stack)


#########################################_Program_begins_from_here_######################################### */


#include "stack.h"

int main()
{
    int option, data, peek;

    /* Initiallising the top as NULL */
    Stack_t *top = NULL;

    printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Exit\nEnter choice: ");

    while (1)
    {

	/*ask user options*/
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     /* To Push the element */

		printf("Enter the element you have to insert at the first : ");
		scanf("%d", &data);
		if ((Push(&top, data)) == FAILURE)
		{
		    printf("INFO : Push operation Failure\n");
		}
		break;

	    case 2:     /* To Pop the top of the value in the stack */

		if ((Pop(&top)) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Pop operation is successfull\n");
		}
		break;

	    case 3:     /* Printing or Dispaying the elements */

		Peep(top);
		break;

	    case 4:     /* To find the Peek element in the stack */

		if ((peek = Peek(&top)) == FAILURE)
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Peek element is %d\n", peek);
		}
		break;

	    case 5:     /* exit */

		return SUCCESS;

	    default:

		printf("Enter proper choice !!\n");
		break;
	}
    }

    return SUCCESS;
}
