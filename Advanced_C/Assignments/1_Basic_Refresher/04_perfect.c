/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to check if number is perfect or not


Sample execution: -

Test Case 1:

Enter a number: 6

Yes, entered number is perfect number

Test Case 2:

Enter a number: 10

No, entered number is not a perfect number

Test Case 3:

Enter a number: -1

Error : Invalid Input, Enter only positive number


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int i, num, sumoffactors = 0;								//initialization
    printf("Enter a number: ");
    scanf("%d", &num);
    if ( num < 0 )										//condition to check if the number is less than 0
    {
	printf("\nError : Invalid Input, Enter only positive number\n");
    }
    else if ( num > 0 )										//condition to check if the number is greater than 0
    {
	for ( i = 1; i < num; i++ )								//loop to calculate the sum of factors (excluding the number itself)
	{
	    if ( num % i == 0 )
	    {
		sumoffactors = sumoffactors + i;
	    }
	}

	if ( sumoffactors == num )								//condition to check if sum of factors is equal to the entered number
	{
	    printf("\nYes, entered number is perfect number\n");
	}
	else
	{
	    printf("\nNo, entered number is not a perfect number\n");
	}

    }

    return 0;
}

