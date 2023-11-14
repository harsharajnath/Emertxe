#include <stdio.h>
int main()
{
    int num1 = 1, num2 = 0;
    if (++num1 || num2++)
    {
	printf("num1 is %d num2 is %d\n", num1, num2);
    }
    num1 = 1, num2 = 0;
    if (num1++ && ++num2)
    {
	printf("num1 is %d num2 is %d\n", num1, num2);
    }
    else
    {
	printf("num1 is %d num2 is %d\n", num1, num2);
    }
    return 0;
}
