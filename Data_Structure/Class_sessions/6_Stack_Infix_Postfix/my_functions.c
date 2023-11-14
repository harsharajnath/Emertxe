#include "main.h"

/* function to find the length of string */ 
int my_strlen(char *str)
  {
  int count = 0;
  while(*str++)
  {
  count++;
  }
  return count;
  }




/* function to indentify if enter character is a symbol */
int isOperator(char sym)
{
    switch(sym)
    {
	case '*':
	case '+':
	case '-':
	case '{':
	case '}':
	case '(':
	case ')':
	case '/':
	case '%':
	    return 1;
	    break;
	default:
	    return 0;

    }
}




/* function to evaluate a postfix expression */
int expressionEvaluation(int valueA, int valueB, char sym )
{
    int a, b;

    if(valueA >= '0' && valueA <= '9')
    {
	a = (valueA - '0');
    }
    else
    {
	a = valueA;
    }	

    if(valueB >= '0' && valueB <= '9')
    {
	b = (valueB - '0');
    }
    else
    {
	b = valueB;
    }

    switch(sym)
    {
	case '+':
	    return (a + b);
	    break;
	case '-':
	    return (a - b);
	    break;
	case '*':
	    return (a * b);
	    break;
	case '/':
	    return (a / b);
	    break;
	case '%':
	    return (a % b);
	    break;
	default:
	    break;
    }	
}

