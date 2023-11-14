#include "main.h"
#include <string.h>

int main()
{
    char Infix_exp[50], Postfix_exp[50], ch;
    int choice, result;
    Stack_t stk;
    stk.top = -1;

    printf("Enter the Infix expression : ");
    scanf("%s", Infix_exp);

    Infix_Postfix_conversion(Infix_exp, Postfix_exp, &stk);
    
    printf("PostFix expression : %s\n", Postfix_exp);
    
    stk.top = -1;
    
    result = Postfix_Eval(Postfix_exp, &stk);
    
    printf("\nResult : %d\n", result);
    
    return 0;
}

