/*


Name: Harsharaj Nath
Date of Submission: 09-06-22
Description: WAP to get 'n' bits of a given number


Sample Execution: 

Test Case 1:

Enter the number: 10

Enter number of bits: 3

Result = 2

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Result = 3


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int get_nbits(int, int);					//function prototype 

int main()
{
    int num, n, res = 0;					//initialization

    printf("Enter num and n:");
    scanf("%d%d", &num, &n);					//taking value of num and n from the user

    res = get_nbits(num, n);					//function call

    printf("Result = %d\n", res);				//printing the result
}

int get_nbits(int num, int n)					//function definition
{
    int result;
    
    result = ((1 << n) - 1) & num;				//logic
    
    return result;						//returning the result
}

