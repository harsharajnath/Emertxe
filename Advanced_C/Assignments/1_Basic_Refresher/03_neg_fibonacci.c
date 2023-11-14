/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to generate negative Fibonacci numbers


Sample execution: -

Test Case 1 :

Enter a number: -8

0, 1, -1, 2, -3, 5, -8

Test Case 2:

Enter a number: -10

0, 1, -1, 2, -3, 5, -8

Test Case 3:

Enter a number: -21

0, 1, -1, 2, -3, 5, -8, 13, -21

Test Case 4: 

Enter a number: -13

0, 1, -1, 2, -3, 5, -8, 13

Test Case 4: 

Enter a number: 13

Invalid input


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
int main()
{
    int n, term1 = 0, term2 = 1, nextterm = 0;								//initialization
    printf("Enter a number: ");
    scanf("%d", &n);
    if ( n == 0 )											//comdition to check if the number is 0
    {
	printf("\n%d\n", term1);
    }
    else if ( n < 0 )											//condition to check if the number is less than 0
    {
	nextterm = term1 - term2;
	printf("\n%d, %d, ", term1, term2);
	while(( nextterm >= n && nextterm < 0) || (nextterm > 0 && nextterm <= -n ))			//logic to calculate the negative fibonacci numbers
	{
	    printf("%d", nextterm);
	    term1 = term2;
	    term2 = nextterm;
	    nextterm = term1 - term2;
	    if (( nextterm >= n && nextterm < 0) || (nextterm > 0 && nextterm <= -n ))
	    {
		printf(", ");
	    }
	}
	printf("\n");
    }
    else												//error message for invalid input
    {
	printf("\nInvalid input\n");
    }

    return 0;
}

