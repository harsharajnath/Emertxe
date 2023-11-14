#include<stdio.h>

/* Program to find the largest of two numbers */

int main()
{
    int num1, num2;
    printf("\n**Program to find the largest of two numbers**\n\n");
    printf("Enter 1st number: \n");
    scanf("%d", &num1);
    printf("Enter 2nd number: \n");
    scanf("%d", &num2);
    
    if ( num1 > num2 )
    {
	printf("%d is greater than %d\n", num1, num2);
    }
    else if ( num1 < num2 )
    {
	printf("%d is greater than %d\n", num2, num1);
    }
    else
    {
	printf("Both numbers are equal\n");
    }

    return 0;
}
