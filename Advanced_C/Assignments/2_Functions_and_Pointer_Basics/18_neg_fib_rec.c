/*


Name: Harsharaj Nath
Date of Submission: 25-06-22
Description: WAP to generate negative fibbonacci numbers using recursion


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

Enter a number: 21
Invalid input


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void negative_fibonacci(int, int, int, int);                                    //function prototype

int main()
{
    int limit, term1 = 0, term2 = 1, nextterm = 0;                              //initialization

    printf("Enter the limit : ");
    scanf("%d", &limit);                                                        //taking limit from user

    if ( limit <= 0 )                                                           //if limit is <= 0 then function call
    { 
	negative_fibonacci(limit, 0, 1, 0);
	printf("\n");
    }
    else									//error message for invalid input
    {
	printf("Invalid input\n");
    }

    return 0;
}

void negative_fibonacci(int limit, int term1, int term2, int nextterm)          //function definition
{
    static int flag = 0;                                                        //initialization
    if ( limit == 0 )								//condition to check if the number is 0
    {
	printf("%d\n", term1);
    }

    else if ( limit < 0 )							//condition to check if the number is less than 0
    {
	nextterm = term1 - term2;
	if (( nextterm >= limit && nextterm < 0) || (nextterm > 0 && nextterm <= -limit ))          //terminating condition for recursive function call
	{
	    if ( flag == 0 )                                                                        //condition to print the 1st two terms only once
	    {   
		printf("%d, %d, ", term1, term2);
		flag = 1;
	    }

	    nextterm = term1 - term2;                                                               //logic to calculate the next term

	    if (( nextterm >= limit && nextterm < 0) || (nextterm > 0 && nextterm <= -limit ))	    //logic to calculate the fibonacci numbers
	    {
		printf("%d", nextterm);
		term1 = term2;
		term2 = nextterm;
		nextterm = term1 - term2;
		if (( nextterm >= limit && nextterm < 0) || (nextterm > 0 && nextterm <= -limit ))
		{
		    printf(", ");
		}
	    }

	    negative_fibonacci(limit, term1, term2, nextterm);                                     //recursive function call
	}
    }
}
