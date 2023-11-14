#include "main.h"

int Infix_Postfix_conversion(char *Infix_exp, char *Postfix_exp, Stack_t *stk)
{
    int infixexplen;
    int j = 0;

    //get the legth of the infixexp
    infixexplen = my_strlen(Infix_exp);

    //push the values into stack and pop to get postfix exp while traversing
    for(int i = 0; i < infixexplen; i++)
    {
	//if the operator is '(' then push this onto stack
	if(Infix_exp[i] == '(')
	{
	    push(stk, Infix_exp[i]);
	}
	else if(! isOperator(Infix_exp[i]))
	{
	    Postfix_exp[j] = Infix_exp[i];
	    j++;
	}
	//if the operator is ')'
	else if (Infix_exp[i] == ')')
	{
	    //if there are no other inner brackets
	    while (peek(stk) != '(')
	    {
		//get the operator from the top and save it onto postfix and increment the index
		Postfix_exp[j] = peek(stk);
		pop(stk);
		j++;
	    }
	    //pop that operator out of the stack, as it is copied
	    pop(stk);
	}
	//for any other operators
	else
	{
	    //pop out the operators and save in prefixexp till it becomes less than
	    while ( priority(peek(stk)) >= priority(Infix_exp[i]) )
	    {
		Postfix_exp[j] = peek(stk);
		pop(stk);
		j++;
	    }
	    //once the stack is cleared of that , push the new operator
	    push(stk, Infix_exp[i]);
	}

    }

    //after the operator check, till stack becomes empty, pop the values and save in prefixexp and increment the index
    while (stk -> top != -1)
    {
	Postfix_exp[j] = peek(stk);
	pop(stk);
	j++;
    }

    //make prefixexp string
    Postfix_exp[j] = '\0';

    return 0;
}
