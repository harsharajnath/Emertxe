/*


Name: Harsharaj Nath
Date of Submission: 05-11-22
Description: Implement stack using array

Implement the stack using array:
1.push(stack, data)
2.pop(stack)
3.peek(stack, data)
4.peep(stack)


#########################################_Program_begins_from_here_######################################### */


#include "stack.h"

//function to create a stack
int create_stack(Stack_t *stk, int size)
{
    stk -> stack = malloc(sizeof(int) * size);          //allocating memory dynamically

    //checking if memory allocation is successful or not
    if(stk -> stack == NULL)
    {
	return FAILURE;
    }

    stk -> capacity = size;     //assigning the capacity
    stk -> top = -1;        //assigning top with -1

    return SUCCESS;
}


int main()
{
    //variable declaration
    int choice, element, peek, size;
    Stack_t stk;

    //taking stack size from user
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    create_stack(&stk, size);   //function call for create_stack()

    printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Exit\nEnter your choice : ");

    while (1)
    {
	//taking the menu choice from user
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:     //push operation
		printf("Enter the element to be pushed in stack : ");
		scanf("%d", &element);
		if (Push(&stk, element) == FAILURE)     //function call for push()
		{
		    printf("INFO : Stack Full\n");
		} 
		break;

	    case 2:     //pop operation
		if (Pop(&stk) == FAILURE)       //function call for pop()
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Pop operation is successfull\n");
		}
		break;

	    case 3:     //peep operation
		Peep(stk);      //function call for peep()
		break; 

	    case 4:     //peek operation
		if ((peek = Peek(&stk)) == FAILURE)     //function call for peek()
		{
		    printf("INFO : Stack is empty\n");
		}
		else
		{
		    printf("INFO : Peek element is %d\n", peek);
		}
		break;

	    case 5:     //exit    
		return SUCCESS;

	    default:
		printf("Invalid Choice.\n");
		break;
	}
    }
    return 0;
}
