#include "main.h"

/* functon to evaluate the postfix expression */
int Postfix_Eval(char *Postfix_exp, Stack_t *stk)
{
    /* variable declaration */
    int postfix_exp_len;
    char value_A, value_B;
    int evaluation_result;

    /* get the length of the postfix expression */
    postfix_exp_len = my_strlen(Postfix_exp);

    /* push the values into stack and pop to get values from postfix expression while traversing*/
    for(int i = 0; i < postfix_exp_len; i++)
    {
	/* if not any operator, push postfix expression value into stack */
	if(! is_operator(Postfix_exp[i]))
	{
	    push(stk, Postfix_exp[i]);
	}

	/* if an operator */
	else if(is_operator(Postfix_exp[i]))
	{
	    /* store the value of top element in value B and pop */
	    value_B = peek(stk);
	    pop(stk);

	    /* store the value of top element in value A and pop */
	    value_A = peek(stk);
	    pop(stk);

	    /* evaluate B op A using the operator currently the postfix expression is containing */
	    evaluation_result = expression_evaluation(value_A, value_B, Postfix_exp[i]);

	    /* push the calculated value onto the stack */
	    push(stk, evaluation_result);
	}
    }

    /* after the whole evaluation only the final result should be there in the stack */
    return (peek(stk));
}
