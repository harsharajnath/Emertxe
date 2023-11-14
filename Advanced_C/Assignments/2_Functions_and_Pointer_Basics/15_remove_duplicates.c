/*


Name: Harsharaj Nath
Date of Submission: 24-06-22
Description: WAP to remove duplicate elements in a given array


Sample execution: -

Test Case 1:

Enter the size: 5

Enter elements into the array: 5 1 3 1 5

After removing duplicates: 5 1 3

Test Case 2:

Enter the size: 5

Enter elements into the array: 2 1 1 1 5

After removing duplicates: 2 1 5


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void fun(int *arr1, int size, int *arr2, int *new_size);                        //function prototype

int main()
{
    int size, new_size = 0;                                                     //initializtion

    printf("Enter the size: ");
    scanf("%d", &size);                                                         //Read size from the user

    int arr1[size];                                                             //declaring the arrays
    int arr2[size];

    printf("Enter elements into the array: ");
    for ( int i = 0; i < size; i++ ) 						//Reading elements into the array
    {
	scanf("%d", &arr1[i]);
    }

    fun( arr1, size, arr2, &new_size );                                         //function call

    printf("After removing duplicates: ");                                      

    for ( int i = 0; i < new_size; i++ ) 					//printing array after removing the duplicates
    {
	printf("%d ", arr2[i]);
    }

    printf("\n");

    return 0;
}

void fun(int *arr1, int size, int *arr2, int *new_size)                         //function definition
{
    int i, j, count;                                                            //declaration
    count = 0;                                                                  //initialization of count variable for element position in deduplicated array

    for ( i = 0; i < size; i++ )                                                //loop to remove the duplicate elements
    {
	if( i == 0 )                                                            //condition to check if it is the 1st element of array
	{
	    arr2[i] = arr1[i];                                                  //if yes, then store it into the deduplicated array
	    (*new_size)++;                                                      //incrementing the new size (for the deduplicated array)
	    count++;                                                            //incrementing the count
	}
	else
	{
	    int flag;                                                           //flag initialization

	    for ( j = 0; j < i; j++ )
	    {
		if ( arr1[j] == arr1[i] )                                       //condition to check if any duplicate element present
		{
		    flag = 1;                                                   //if any duplicate found for i element, the loop will break and flag is set
		    break;
		}
		else
		{
		    flag = 0;
		}
	    }

	    if ( flag == 0 )                                                    //if duplicate element not found, then i element will be stored to deduplicated array
	    {
		arr2[count] = arr1[i];                                          //storing the element
		(*new_size)++;                                                  //incrementing the new_size
		count++;                                                        //incrementing the count
	    }
	}
    }
}
