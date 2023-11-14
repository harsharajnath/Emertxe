#include<stdio.h>

/* Program to find the greatest of three numbers */

int main()
{
    int num1, num2, num3;
    printf("\n**Program to find the largest of three numbers**\n\n");
    printf("Enter 1st number: \n");
    scanf("%d", &num1);
    printf("Enter 2nd number: \n");
    scanf("%d", &num2);
    printf("Enter 3rd number: \n");
    scanf("%d", &num3);

    if ( num1 >= num2 && num1 >= num3 )
    {
	printf("%d is the largest\n", num1);
    }
    else if ( num2 >= num1 && num2 >= num3 )
    {
	printf("%d is the largest\n", num2);
    }
    else
    {
	printf("%d is the largest\n", num3);
    }

    return 0;
}
