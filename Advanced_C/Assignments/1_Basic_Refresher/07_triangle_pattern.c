/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to print triangle pattern as shown below


Sample Output:
Test Case 1:
Enter the number: 4
1 2 3 4
5   6
7 8
9

Test Case 2:
Enter the number: 5
1 2 3 4 5
6     7
8   9
10 11
12


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int row, col, num, count = 0;						//initialization
    printf("Enter the number: ");
    scanf("%d", &num);								//taking input from the user
    printf("\n");
    for ( row = 1; row <= num; row++)						//loop for printing rows
    {
	for ( col = row; col <= num; col++)					//loop for printing columns
	{
	    if ( row == 1 || row == col || col == num )				//condition to print the digits
	    {
		count++;
		printf("%d ", count);
	    }
	    else								//condition to print the space
	    {
		printf("  ");
	    }
	}
	printf("\n");
    }
    return 0;
}
