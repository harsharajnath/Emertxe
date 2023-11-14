/*


Name: Harsharaj Nath
Date of Submission: 01-07-22
Description: Print the values in sorted order without modifying or copying array


Sample execution: -

Test Case 1:

Enter the size : 5
Enter 5 elements 
10 1 3 8 -1
After sorting: -1 1 3 8 10
Original array values 10 1 3 8 -1

Test Case 2:

Enter the size : 7
Enter 7 elements 
1 3 2 5 4 7 6
After sorting: 1 2 3 4 5 6 7
Original array values 1 3 2 5 4 7 6

Test Case 3:

Enter the size : 4
Enter 4 elements 
-1 -2  4 3
After sorting: -2 -1 3 4
Original array values -1 -2  4 3


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void print_sort(int *, int);					                           //function prototype

int main()
{
    int size, iter;						                           //declaration

    printf("Enter the size of the array :\n");
    scanf("%d", &size);						                           //taking size of array from user

    int arr[size];

    printf("Enter the %d elements\n", size);
    for (iter = 0; iter < size; iter++)				                            //taking the array elements
    {
	    scanf("%d", &arr[iter]);
    }

    printf("After sorting ");

    print_sort(arr, size);					                            //function call

    printf("\nOriginal array values ");
    for (iter = 0; iter < size; iter++)				                            //printing the original array
    {
	    printf("%d ", arr[iter]);
    }
    printf("\n");
    return 0;
}

void print_sort(int *arr, int size)				                           //function definition
{
    int largest = arr[0];                                            		           //initializtion
    int smallest = arr[0];
    int second_smallest = arr[0];
    int i, j, k, l, m;
    int limit = size;                                                           	   //initializing limit with size
    
    for ( i = 0; i < size; i++ )					                   //loop to find the largest element and smallest element
    {
	    if ( arr[i] > largest )
	        largest = arr[i];
	    if ( arr[i] < smallest )
	        smallest = arr[i];
    }

    for ( j = 0; j < limit; j++ )                                             		  //main loop
    {
	    int count = 0;                                                          	  //initializing count with 0

	    for( k = 0; k < size; k++)                                                    //loop to check if duplicate elements are present
	    {
	        if ( arr[k] == smallest )
	        {
		        count++;
	        }
	    }
	    
	    if ( count == 1 )                                                              //condition if no duplicate found
	    {
	        printf("%d ", smallest);                                                   //print the smallest element
	    }
	    else if( count > 1)                                                            //condition if duplicates are present
	    {
	        for ( l = 1; l <= count; l++ )                                             //printing the duplicate element the number of times it has repeated in the original array
	        {
		        printf("%d ", smallest);
	    	    limit--;                                                               /* accordingly decreasing the limit, else last elements will get printed addition n times
	    	                                                                           where n = sum of [each duplicate element total count - 1] */
	        }
	        limit++;                                                                   //adjusting the limit by 1 because we want limit = count - 1 and above loop gives us limit = count
	    }


	    second_smallest = largest;
	    for ( m = 0; m < size; m++ )			                           //loop to find the second smallest element
	    {
	        if ( arr[m] > smallest && arr[m] < second_smallest )
	        {
		        second_smallest = arr[m];
	        }
	    }

	    smallest = second_smallest;				                           //updating the smallest element with second smallest element
    }
}
