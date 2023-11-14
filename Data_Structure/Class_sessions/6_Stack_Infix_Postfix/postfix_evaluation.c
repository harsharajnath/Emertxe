#include "main.h"

int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    int postfixexplen;

    char int_valueA, int_valueB, int_result;

    //get the length of the postfixexp
    postfixexplen = my_strlen(Postfix_exp);

    //push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
    for(int i = 0; i < postfixexplen; i++)
    {
	//if it is not any operator, push postfixexp into evaluationStackArray
	if(! isOperator(Postfix_exp[i]))
	{
	    push(stk, Postfix_exp[i]);
	}
	//else, if it is an operator

	if(isOperator(Postfix_exp[i]))
	{
	    // Pop the stack and call the value B
	    int_valueB = peek(stk);
	    pop(stk);

	    // Pop the stack and call the value A
	    int_valueA = peek(stk);
	    pop(stk);

	    //Evaluate B op A using the operator just found.
	    int_result = expressionEvaluation(int_valueA, int_valueB, Postfix_exp[i]);

	    //change this int to ascii equivalent
	    //int_result += '0';

	    //Push the resulting value onto the stack
	    push(stk, int_result);
	}
    }

    return (peek(stk));
}
