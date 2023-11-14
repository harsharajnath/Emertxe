/*


Name: Harsharaj Nath
Date of Submission: 20-07-22
Description: Variance calculation with dynamic arrays


Sample execution: -

Test Case 1:

Enter the no.of elements : 10

Enter the 10 elements:
[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31
Variance is 40.000000


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <stdlib.h>

float variance(float *, int);                                                   //function prototype of variance()

int main()
{
    int n;
    float var;

    printf("Enter the no. of Elements: ");
    scanf("%d", &n);                                                            //reading no. of elements from user

    float *array;
    array = malloc(n * sizeof(float));                                          //dynamically allocating memory for the array

    if (array == NULL)                                                          //if memory allocation fails
    {
	printf("Error - Memory not allocated. Try with less no. of Elements.\n");
    }
    else 
    {
	printf("Enter the %d elements\n", n);
	for(int i = 0; i < n; i++)				                                //reading the array elements
	{
	    printf("[%d] -> ", i); 
	    scanf("%f", &array[i]);
	}

	var = variance(array, n);                                               //function call

	printf("Variance is %f\n", var);                                        //printing the value of variance
    }

    free(array);                                                                //freeing the memory
    array = NULL;

    return 0;
}

float variance(float *array, int n)                                             //function definition
{
    float mean;
    float sum = 0;
    float sum_dsquare = 0;
    float variance;

    for(int i = 0; i < n; i++)                                                  //sum of all elements
    {
	sum = sum + array[i];
    }

    mean = sum / n;                                                             //calculating the mean;

    for(int i = 0; i < n; i++)                                                  //updating the array with deviation
    {
	array[i] = array[i] - mean ;
    }

    for(int i = 0; i < n; i++)                                                  //updating the array with deviation square
    {
	array[i] = array[i] * array[i] ;
    }

    for(int i = 0; i < n; i++)                                                  //calculating the sum of deviation square
    {
	sum_dsquare = sum_dsquare + array[i] ;
    }

    variance = sum_dsquare / n;                                                 //calculation the variance

    return variance;                                                            //returning the variance value
}

