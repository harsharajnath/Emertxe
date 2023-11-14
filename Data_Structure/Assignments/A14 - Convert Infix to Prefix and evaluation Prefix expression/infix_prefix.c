#include "main.h"

/* function to convert infix expression to prefix expression */
int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    /* variable declaration */
    int infix_exp_len;
    int j = 0;

    /* get the length of the infix expression */
    infix_exp_len = my_strlen(Infix_exp);

    /* push the values into stack and pop to get postfix expression while traversing from behind */
    for(int i = 0; i < infix_exp_len; i++)
    {
	/* if not an operator */
	if(! is_operator(Infix_exp[i]))
	{	
	    Prefix_exp[j] = Infix_exp[i];
	    j++;
	}
	/* if an operator */
	else 
	{
	    /* if the operator is ')' then push this onto stack */
	    if(Infix_exp[i] == ')')
	    {
		push(stk, Infix_exp[i]);
	    }
	    /* if the operator is '(' */
	    else if (Infix_exp[i] == '(')
	    {
		/* if there are no other inner brackets */
		while (peek(stk) != ')')
		{
		    /* get the operator from the top and save it onto prefix and increment the index */
		    Prefix_exp[j] = peek(stk);
		    pop(stk);
		    j++;
		}
		/* pop that operator out of the stack, as it is copied */
		pop(stk);
	    }
	    /* for other operators */ 
	    else
	    {
		/* check for priority, if the top of the stack operator is less then push then push the new operator */
		if ( priority(peek(stk)) <= priority(Infix_exp[i]) )
		{
		    push(stk, Infix_exp[i]);
		}
		else
		{
		    /* pop out the operators and save in perfix array till it becomes less than */
		    while ( priority(peek(stk)) >= priority(Infix_exp[i]) )
		    {
			Prefix_exp[j] = peek(stk);
			pop(stk);
			j++;
		    }
		    /*once the stack is cleared of that , push the new operator */
		    push(stk, Infix_exp[i]);
		}
	    }	
	}
    }

    /* after the operator check, till stack becomes empty, pop the values and save in prefix array and increment the index */
    while (stk -> top != -1)
    {
	Prefix_exp[j] = peek(stk);
	pop(stk);
	j++;
    }

    /* adding null character at the end of prefix array */
    Prefix_exp[j] = '\0';

    return 0;
}
