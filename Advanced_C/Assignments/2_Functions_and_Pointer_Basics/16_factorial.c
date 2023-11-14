/*


Name: Harsharaj Nath
Date of Submission: 25-06-22
Description: WAP to find factorial of given number using recursion


Sample execution: -

Test Case 1:

Enter the value of N : 7
Factorial of the given number is 5040

Test Case 2:

Enter the value of N : 5
Factorial of the given number is 120

Test case 3:

Enter the value of N : -1
Invalid Input

Test case 4:

Enter the value of N : 0
Factorial of the given number is 1


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int main()
{
    static int num;                                                             //declaration
    static unsigned long long int fact = 1;
    static int flag = 0;

    if ( flag == 0 )                                                            //to read the num value only once
    {
	printf("Enter the value of N :\n");
	scanf("%d", &num);
	flag = 1;
    }
    if ( num == 0 )                                                             //condition to check if num is 0
    {
	printf("Factorial of the given number is 1\n");
    }
    else if ( num > 0 )                                                         //condition to check if entered num is a positive number
    {
	fact = fact * num--;                                                    //calculating the factorial

	if ( num < 1 )                                                          //terminating condition for recursive call
	{
	    printf("Factorial of the given number is %lld\n", fact);              //printing the factorial value
	}
	else
	    main();                                                             //recursive function call
    }
    else
    {
	printf("Invalid Input\n");                                              //if entered num is negative number
    }
}
