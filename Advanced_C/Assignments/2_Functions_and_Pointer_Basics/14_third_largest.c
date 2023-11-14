/*


Name: Harsharaj Nath
Date of Submission: 21-06-22
Description: WAP to find 3rd largest element in an array


Sample Execution:

Test Case 1:

Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Third largest element of the array is 4

Test Case 2:

Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Third largest element of the array is 11


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int third_largest(int *, int);                                                  //function prototype

int main()
{
    int size, ret;                                                              //initializtion

    printf("Enter the size of the array : ");
    scanf("%d", &size);                                                         //Read size from the user

    int arr[size];

    for ( int i = 0; i < size; i++ ) 						//Reading elements into the array
    {
	scanf("%d", &arr[i]);
    }

    ret = third_largest(arr, size);                                             //funtion call

    printf("Third largest element of the array is %d\n", ret);                  //printing the third largest element
}

int third_largest(int *arr, int size)                                           //function definition
{
    int largest = arr[0];                                                       //initializtion
    int smallest = arr[0];
    int second_largest = arr[0];
    int third_largest = arr[0];

    for ( int i = 0; i < size; i++ )						//loop to find the largest element and smallest element
    {
	if ( arr[i] > largest )
	    largest = arr[i];
	if ( arr[i] < smallest )
	    smallest = arr[i];
    }

    int difference1 = largest - smallest;                                       //maximum possible difference

    for ( int i = 0; i < size; i++ )						//loop to find the second largest element
    {
	if ( arr[i] < largest )                                                 //condition to exclude the largest element
	{
	    if ( largest - arr[i] <= difference1 )                              //logic - 2nd largest element will be the one which have least difference
	    {
		difference1 = largest - arr[i];
		second_largest = arr[i];
	    }
	}
    }

    int difference2 = second_largest - smallest;                                //maximum possible difference between second largest element and smallest element

    for ( int i = 0; i < size; i++ )						//loop to find the third largest element
    {
	if ( arr[i] < second_largest )                                          //condition to exclude the largest and second largest element
	{
	    if ( second_largest - arr[i] <= difference2 )                       //logic - 3rd largest element will be the one which have least difference from second largest element
	    {
		difference2 = second_largest - arr[i];
		third_largest = arr[i];
	    }
	}
    }
    return third_largest;                                                       //returning the third largest element
}
