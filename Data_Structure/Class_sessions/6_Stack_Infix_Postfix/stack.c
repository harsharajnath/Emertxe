#include "main.h"

int priority(char opr)
{
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

void push(Stack_t *stk, int data)
{
    ++(stk -> top);
    stk -> stack[stk -> top] = data;
}

void pop(Stack_t *stk)
{
    if (stk -> top != -1)
	--(stk -> top);
}

int peek(Stack_t *stk)
{
    if (stk -> top != -1)
    {
	return stk -> stack[stk -> top];
    }
    return -1;
}


