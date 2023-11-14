/*


Name: Harsharaj Nath
Date of Submission: 02-06-22
Description: WAP to count number of set bits in a given number and print parity


Sample execution: -

Test Case 1:

Enter the number : 7

Number of set bits = 3

Bit parity is Odd

Test Case 2:

Enter the number : 15

Number of set bits = 4

Bit parity is Even

Test Case 3:

Enter the number : 6

Number of set bits = 2

Bit parity is Even


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int i, num, count = 0;						//initialization
    printf("Enter the number : ");
    scanf("%d", &num);							//reading input from user

    for ( i = 0; i<32; i++ )						//loop for counting the set bit
    {
	if ( num & (1<<(31 - i)))					//condition to increment the count variable
	{
	    count++;
	}
    }

    printf("Number of set bits = %d\n", count);

    if ((count & 1) == 0)						//condition to check if count is even or odd (Even if LSB=0, Odd if LSB=1)
    {
	printf("Bit parity is Even\n");
    }
    else
    {
	printf("Bit parity is Odd\n");
    }

    return 0;
}
