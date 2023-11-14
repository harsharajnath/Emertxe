/*


Name: Harsharaj Nath
Date of Submission: 30-07-22
Description: WAP to implement fragments using Array of Pointers


Sample Execution:

Test case 1:

Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
#include<stdlib.h>

int fragments(float **, int *, int);                                            //function prototype of fragment()
void print(float **, int *, int);                                               //function prototype of print()

int main()
{
    int n, col;
    printf("Enter no.of rows : ");
    scanf("%d", &n);	                                                        //taking number of rows from user

    int row[n];                                                                 //declaring row array to store the value of no. of columns in each row
    float *array[n];                                                            //array of pointers


    for(int i = 0; i < n; i++)
    {
	printf("Enter no of columns in row[%d] : ", i);
	scanf("%d", &row[i]);                                                   //reading the no. of columns in each row
	array[i] = malloc((row[i] + 1) * sizeof(float));                        //dynamically allocating memory for every row
    }


    for(int i = 0; i < n; i++)
    {
	printf("Enter %d values for row[%d] : ", row[i], i);

	for(int j = 0; j < row[i]; j++)
	{
	    scanf("%f", &array[i][j]);                                          //reading column values
	}
    }

    for(int i = 0; i < n; i++)                                                  //loop to calculate and store average value
    {
	float sum = 0;
	for(int j = 0; j < row[i]; j++)
	{
	    sum = sum + array[i][j];                                            //sum of all elements of each row
	}

	array[i][row[i]] = sum / row[i];                                        //calculating the average and storing it in the last element of each row
    }

    printf("Before sorting output is:\n");
    print(array, row, n);                                                       //function call for printing

    fragments(array, row, n);                                                   //function call for fragments

    printf("After sorting output is:\n");
    print(array, row, n);                                                       //function call for printing

    free(*array);                                                               //freeing the dynamically allocated memory
    *array = NULL;
    return 0;

}
void print(float **array, int *row, int n)                                      //function definition for print()
{
    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j <= row[i]; j++)
	{
	    printf("%f ", array[i][j]);
	}
	printf("\n");
    }
}
int fragments(float **array, int *row, int n)                                   //function definition for fragments()
{
    float *temp;
    int temp_row;
    for (int i = 0; i < n ; i++ )
    {
	for (int j = 1; j < n; j++ )
	{
	    if(array[j][row[j]] < array[j-1][row[j-1]])                         //comparing the average values
	    {                                                                   //and sorting them in ascending order             
		temp = array[j];
		array[j] = array[j-1];
		array[j-1] = temp;

		temp_row = row[j];                                              //also updating the values in row[] accordingly
		row[j] = row[j-1];
		row[j-1] = temp_row;
	    }
	}
    }
}
