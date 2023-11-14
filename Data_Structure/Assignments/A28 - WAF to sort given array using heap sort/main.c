/*


Name: Harsharaj Nath
Date of Submission: 25-11-22
Description: WAF to sort given array using heap sort.


Sample execution: -

Input:	5 4 3 2 1
Output:	1 2 3 4 5


#########################################_Program_begins_from_here_######################################### */


#include "main.h"

/* Main Function */
int main()
{
    int i, limit;

    /* Scanning the size */
    printf("Enter the size of an array\n");
    scanf("%d", &limit);

    /* Declaring the array with size */
    int heap[limit];

    printf("Enter the array elements\n");
    for (i = 0; i < limit; i++)
    {
	/* Scanning the array elements */
	scanf("%d", &heap[i]);
    }

    /* function call for build_maxheap() */
    build_maxheap(heap, limit);

    /* Calling the function to heap sort */
    heap_sort(heap, limit);

    printf("Sorted array is : ");
    for (i = 0; i < limit; i++)
    {
	printf("%d ", heap[i]);
    }

    return 0;
}
