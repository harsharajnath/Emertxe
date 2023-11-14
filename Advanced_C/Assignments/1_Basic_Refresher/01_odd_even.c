/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to check if number is odd or even and mention its sign too.


Sample execution: -

Test Case 1:

Enter the value of 'n' : -2

-2 is negative even number

Test Case 2:

Enter the value of 'n' : 2

2 is positive even number

Test Case 3:

Enter the value of 'n' : 0

0 is neither odd nor even


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
int main()
{
    int num;
    printf( "\nEnter the value of 'n' : " );
    scanf( "%d", &num );
    if ( num > 0 )										//condition to check if number is positive
    {
	if ( num % 2 == 0 )									//condition to check if number is even
	{
	    printf( "\n%d is positive even number\n\n", num);
	}
	else
	{
	    printf( "\n%d is positive odd number\n\n", num);
	}
    }
    else if ( num < 0 )										//condition to check if number is negative
    {
	if ( num % 2 == 0 )									//condition to check if number is even
	{
	    printf( "\n%d is negative even number\n\n", num);
	}
	else
	{
	    printf( "\n%d is negative odd number\n\n", num);
	}
    }
    else											//condition if number is 0
    {
	printf("\n0 is neither odd nor even\n\n");
    }

    return 0;

}
