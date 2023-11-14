/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to print the numbers in X format as shown below


Sample execution: -

Test Case 1:
Enter the number: 4
1  4
 23
 23
1  4

Test Case 2:
Enter the number: 5
1   5
 2 4
  3
 2 4
1   5

#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int row, col, num;
    printf("Enter the number: ");
    scanf("%d", &num);									//taking input from the user

    for ( row = 1; row <= num; row++ )							//loop for printing rows
    {
	for ( col = 1; col <= num; col++)						//loop for printing columns
	{
	    if ( row == col )								//logic to print the left diagonal
	    {
	       printf("%d", row);
	    }
	    else if ( row + col - 1 == num )						//logic to print the right diagonal
	    {
		printf("%d", col);
	    }
	    else									//printing the space
	    {
		printf(" ");
	    }
	}
	printf("\n");
    }

    return 0;
}
