#include "main.h"

/* function to push to stack */
void push(Stack_t *stk, int data)
{
    ++(stk -> top);
    stk -> stack[stk -> top] = data;
}

/* function to pop from stack */
void pop(Stack_t *stk)
{
    if (stk -> top != -1)
	--(stk -> top);
}

/* function to peek the topmost element of stack */
int peek(Stack_t *stk)
{
    if (stk -> top != -1)
    {
	return stk -> stack[stk -> top];
    }
    return -1;
}

/* function to check the priority of the operators */
int priority(char opr)
{
    /* using switch case in fall through */
    switch(opr)
    {
	case '{':
	case '}':
	case '(':
	case ')':
	    return 1;
	    break;
	case '+':
	case '-':
	    return 2;
	    break;
	case '*':
	case '/':
	case '%':
	    return 3;
	    break;
	default:
	    return 0;
    }
}
