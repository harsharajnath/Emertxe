/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to print pyramid pattern as shown below


Sample Output:

Test Case 1:
Enter the number: 4
4
3 4
2 3 4
1 2 3 4
2 3 4
3 4
4

Test Case 2:
Enter the number: 5
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int row, col, num, count = 0;					//initialization
    printf("Enter the number: ");
    scanf("%d", &num);							//taking value from the user
    for ( row = 1; row <= num*2; row++ )				//loop to print the rows
    {
	if( row < num + 1 )						//condition for count variable
	{
	    count++;
	}
	else
	{
	    count--;
	}

	for ( col = 1; col <= num; col++ )				//loop to print the columns
	{
	    if ( col >= (num + 1) - count )				//condition to print the digits
	    {
		printf("%d", col);
	    }
	}
	printf("\n");
    }
    return 0;
}

