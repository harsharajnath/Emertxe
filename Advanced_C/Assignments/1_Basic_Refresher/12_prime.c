/*


Name: Harsharaj Nath
Date of Submission: 08-06-22
Description: WAP to print all primes using Sieve of Eratosthenes method


Sample execution: -

Test Case 1:

Enter the value of 'n' : 20

The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19

Test Case 2 :

Enter the value of 'n' : -20

Please enter a positive number which is > 1


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int i, j, num, size, square, limit, n, count1, count2;

    square = 1;
    count1 = 0;
    count2 = 0;


    printf("Enter the value of 'n' : ");			//taking value of n from the user
    scanf("%d", &num);

    if ( num > 1 )						//condition check if n > 1
    {
	n = num;
	size = num - 1;
	int array[size];					//initializing array with size

	for ( i = 2; i <= num; i++ )			//loop to fill the array elements from 2 to given value
	{
	    array[i] = i;
	}


	for ( i = 1; square <= num; i++ )		//loop to find the limit till where we have to do Eratosthenes method
	{
	    square = i * i;
	    limit = i - 1;
	}


	for ( j = 2; j <= limit; j++ )			//logic to replaces multiples of number as 0
	{
	    for ( i = 2; i <= num; i++ )
	    {

		if ( array[i] != j )
		{
		    if ( array[i] % j == 0 )
		    {
			array[i] = 0;
		    }

		}
	    }

	}


	for ( i = 2; i<=n; i++)							//loop to count the number of prime numbers
	{
	    if ( array[i] != 0 )
	    {
		count1++;
	    }
	}


	printf("The primes less than or equal to %d are : ", num);
	for ( i = 2; i<=n; i++)							//loop to print the final prime numbers
	{
	    if ( array[i] != 0 )
	    {
		printf("%d", array[i]);

		if ( count2 < (count1 - 1) )					//condition to print the ","
		{
		    printf(", ");
		    count2++;
		}
	    }

	}
	printf("\n");
    }
    else
    {
	printf("Please enter a positive number which is > 1\n");
    }

    return 0;
}
