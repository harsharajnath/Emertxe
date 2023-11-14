/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to generate positive Fibonacci numbers


Sample execution: -

Test Case 1 :

Enter a number: 8

0, 1, 1, 2, 3, 5, 8

Test Case 2:

Enter a number: 10

0, 1, 1, 2, 3, 5, 8

Test Case 3:

Enter a number: 21

0, 1, 1, 2, 3, 5, 8, 13, 21

Test Case 4:

Enter a number: -21

Invalid input


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
int main()
{
    int n, term1 = 0, term2 = 1, nextterm = 0;					//initialization
    printf("Enter a number: ");
    scanf("%d", &n);
    if ( n == 0 )								//condition to check if the number is 0
    {
	printf("\n%d\n", term1);
    }
    else if ( n == 1 )								//condition to check if the number is 1
    {
	printf("\n%d, %d, %d\n", term1, term2, term2);
    }
    else if ( n > 1 )								//condition to check if the number is greater than 1
    {
	nextterm = term1 + term2;						//logic to calculate the next term
	printf("\n%d, %d, ", term1, term2);
	while( nextterm <= n )							//logic to calculate the fibonacci numbers
	{
	    printf("%d", nextterm);
	    term1 = term2;
	    term2 = nextterm;
	    nextterm = term1 + term2;
	    if ( nextterm <= n )
	    {
		printf(", ");
	    }
	}
	printf("\n");
    }
    else									//error message for invalid input
    {
	printf("\nInvalid input\n");
    }


    return 0;
}
