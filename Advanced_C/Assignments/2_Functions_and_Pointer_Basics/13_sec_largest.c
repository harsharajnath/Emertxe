/*


Name: Harsharaj Nath
Date of Submission: 21-06-22
Description: WAP to find 2nd largest element in an array


Sample execution: -

Test Case 1:

Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Second largest element of the array is 5

Test Case 2:

Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Second largest element of the array is 22


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int sec_largest(int *, int);                                                    //function prototype

int main()
{
    int size, ret;                                                              //initializtion

    printf("Enter the size of the array : ");
    scanf("%d", &size);                                                         //Read size from the user

    int arr[size];

    for ( int i = 0; i < size; i++ ) 							                //Reading elements into the array
    {
	scanf("%d", &arr[i]);
    }

    ret = sec_largest(arr, size);                   							//funtion call

    printf("Second largest element of the array is %d\n", ret);                 //printing the second largest element 
}

int sec_largest(int *arr, int size)                                             //function definition
{
    int largest = arr[0];                                                       //initializtion
    int smallest = arr[0];
    int second_largest = arr[0];

    for ( int i = 0; i < size; i++ )							                //loop to find the largest element and smallest element
    {
	if ( arr[i] > largest )
	    largest = arr[i];
	if ( arr[i] < smallest )
	    smallest = arr[i];
    }

    int difference = largest - smallest;                                        //maximum possible difference

    for ( int i = 0; i < size; i++ )							                //loop to find the second largest element
    {
	if ( arr[i] < largest )                                                 //condition to exclude the largest element
	{
	    if ( largest - arr[i] <= difference )                               //logic - 2nd largest element will be the one which have least difference
	    {
		difference = largest - arr[i];
		second_largest = arr[i];
	    }
	}
    }

    return second_largest;                                                      //returning the second largest element
}
