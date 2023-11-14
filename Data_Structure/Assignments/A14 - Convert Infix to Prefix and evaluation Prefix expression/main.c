/*


Name: Harsharaj Nath
Date of Submission: 10-11-22
Description: Convert Infix to Prefix and evaluation Prefix expression

Implement given below functions.
1. Infix – Prefix converstion 
2. Prefix evaluation

Sample execution: -

1. Infix – Prefix converstion

Cases	1. Single digit numbers
Input	2 * 3 – 3 + 8 / 4 / (1 + 1)
Output	+ – * 2 3 3 / / 8 4 + 1 1
2. Multiple digit numbers
Input	2 * 30 – 3 + 8 / 4 / (10 + 1)
Output	+, -, *, 2, 30, 3, /, /, 8, 4, +, 10, 1

2. Postfix evaluation

Cases	1. Single digit numbers
Input	+ – * 2 3 3 / / 8 4 + 1 1
Output	4
2. Multiple digit numbers
Input	+, -, *, 2, 30, 3, /, /, 8, 4, +, 10, 1
Output	57.18


#########################################_Program_begins_from_here_######################################### */


#include "main.h"

int main()
{
    /* variable declaration */
    char Infix_exp[50], Prefix_exp[50], ch;
    int choice, result;
    Stack_t stk;
    stk.top = -1;

    /* taking infix expression from user */
    printf("Enter the Infix expression : ");
    scanf("%s", Infix_exp);

    /* reversing the infix expression */
    /* function call for strrev() */
    strrev(Infix_exp);

    /* function call Infix_Prefix_conversion() */
    Infix_Prefix_conversion(Infix_exp, Prefix_exp, &stk);

    /* reversing the prefix expression */
    /* function call for strrev() */
    strrev(Prefix_exp);

    printf("PreFix expression : %s\n", Prefix_exp);

    /* resetting the top */
    stk.top = -1;

    /* reversing the prefix expression */
    /* function call for strrev() */
    strrev(Prefix_exp);

    /* function call Prefix_Eval() */ 
    result = Prefix_Eval(Prefix_exp, &stk);

    /* printing the result */
    printf("\nResult : %d\n", result);

    return 0;
}
