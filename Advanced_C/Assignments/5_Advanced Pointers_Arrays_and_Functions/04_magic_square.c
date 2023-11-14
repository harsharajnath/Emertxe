/*


Name: Harsharaj Nath
Date of Submission: 23-07-22
Description: WAP to generate a n*n magic square


Sample execution: -

Test Case 1:

Enter a number: 3
8      1      6
3      5      7
4      9      2

Test Case 2:

Enter a number: 6
Error : Please enter only positive values


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include<stdlib.h>
void magic_square(int **, int);                                                 //function prototype for magic_square()
void print_square(int **, int);                                                 //function prototype for print_square()

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);                                                            //taking the value of n from user

    if( (n < 0) || (( n % 2 ) == 0))                                            //condition check if n is positive odd number
    {
	printf("Error : Please enter only positive odd numbers");
    }
    else
    {
	int **array;                                                            //declaring a double pointer
	array = calloc( n, sizeof(*array));                                     //dynamically allocating memory for row

	for(int i = 0; i < n; i++)
	{
	    array[i] = malloc( n * sizeof(int));                                //dynamically allocating memory for col
	}

	magic_square(array, n);                                                 //function call for magic square
	print_square(array, n);                                                 //function call for printing

	free(array);                                                            //freeing the memory
	array = NULL;
    }

    return 0;
}

void magic_square(int **array, int n)                                           //function definition
{
    int count_limit = n * n;                                                    //maximum count
    int row_limit = n-1;                                                        //maximum row
    int col_limit = n-1;                                                        //maximum col

    int row = 0;                                                                //initial row value
    int col = (n-1) / 2;                                                        //initial col value
    int count = 1;                                                              //initial count value

    int prev_row;                                                               //to store previous value of row
    int prev_col;                                                               //to store previous value of col

    for(int m = 0; m < count_limit; m++)                                        //main loop
    {
	if(count == 1)                                                          //for the 1st iteration
	{
	    array[row][col] = count;                                            //storing the value of count
	    row--;                                                              //one row up
	    col++;                                                              //one col towards right
	    count++;                                                            //incrementing the count
	}
	else
	{
	    if( row < 0 )                                                       //if row value becomes less than 0, set row = max. row value
	    {
		row = row_limit;
	    }

	    if( col > col_limit)                                                //if col value becomes more than col limit, set col = 0
	    {
		col = 0;
	    }

	    if(array[row][col] != 0)                                            //if value of given index not equal to 0
	    {
		row = prev_row;                                                 //set row with previous value of row
		row++;                                                          //increment row by 1
		col = prev_col;                                                 //set col with previous value of col

		if( row < 0 )                                                   //if row value becomes less than 0, set row = max. row value
		{
		    row = row_limit;
		}

		if( col > col_limit)                                            //if col value becomes more than col limit, set col = 0
		{
		    col = 0;
		}

		array[row][col] = count;                                        //storing the value of count                                        
		row--;                                                          //one row up
		col++;                                                          //one col towards right
		count++;                                                        //incrementing the count
	    }
	    else
	    {
		array[row][col] = count;                                        //storing the value of count
		prev_row = row;                                                 //updating with current row value
		prev_col = col;                                                 //updating with current col value
		row--;                                                          //one row up
		col++;                                                          //one col towards right
		count++;                                                        //incrementing the count
	    }
	}
    }
}

void print_square(int **array, int n)                                           //function definition
{
    for (int i = 0; i < n; i++)
    {
	for(int j = 0; j < n; j++)
	{
	    printf("%4d", array[i][j]);
	}
	printf("\n");
    }
}
