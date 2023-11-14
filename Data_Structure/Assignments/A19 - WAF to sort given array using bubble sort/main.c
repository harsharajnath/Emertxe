/*


Name: Harsharaj Nath
Date of Submission: 16-11-22
Description: WAF to sort given array using bubble sort


Sample execution: -

size: 5
Input:	5 4 3 2 1
Output:	1 2 3 4 5


#########################################_Program_begins_from_here_######################################### */


#include "main.h"

/* Main Function */
int main()
{
    /* variable declaration */
    int i, limit, option;

    /* Scanning the size */
    printf("Enter the size of an array\n");
    scanf("%d", &limit);

    /* Declaring the array with size */
    data_t arr[limit];


    printf("Enter the array elements\n");
    for (i = 0; i < limit; i++)
    {
	/* Scanning the array elements */
	scanf("%d", &arr[i]);
    }

    /* Calling the function to bubble sort */
    bubble(arr, limit);

    printf("Sorted array is : ");
    for (i = 0; i < limit; i++)
    {
	printf("%d ", arr[i]);
    }

    return 0;
}
