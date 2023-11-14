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


/* function to reverse the string */
void strrev(char *string)
{
    int i = 0;
    int strlen = 0;
    int index = 0;
    int len;
    int limit;
    char swap;

    len = my_strlen(string) - 1;
    limit = len / 2;

    /* reversing the string */
    for ( int j = 0; j <= limit; j++ )
    {
	swap = string[index];
	string[index] = string[len];
	string[len] = swap;

	index++;
	len--;
    }
}


/* function to indentify if enter character is an operator */
int is_operator(char sym)
{
    /* using switch case in fall through */
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


/* function to evaluate a prefix expression */
int expression_evaluation(int value_A, int value_B, char opr )
{
    int a, b;

    /* if value is single digit i.e between '0' and '9', converting to integer then storing */
    if(value_A >= '0' && value_A <= '9')
    {
	a = (value_A - '0');
    }
    /* if multiple digit, storing as it is */
    else
    {
	a = value_A;
    }	

    /* if value is single digit i.e between '0' and '9', converting to integer then storing */
    if(value_B >= '0' && value_B <= '9')
    {
	b = (value_B - '0');
    }
    /* if multiple digit, storing as it is */
    else
    {
	b = value_B;
    }

    /* switch case for various operations */
    switch(opr)
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
