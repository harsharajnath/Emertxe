#include <stdio.h>
/* Factorial of 3 numbers */
int factorial(int number)
{
    if (number <= 1) /* Base Case */
    {
	return 1;
    }
    else /* Recursive Case */
    {
	return number * factorial(number-1);
    }
}
int main()
{
    int ret;
    ret = factorial(3);
    printf("Factorial of 3 is %d\n", ret);
    return 0;
}
