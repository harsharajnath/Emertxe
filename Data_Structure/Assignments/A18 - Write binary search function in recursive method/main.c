/*


Name: Harsharaj Nath
Date of Submission: 16-11-22
Description: Write binary search function in recursive method


Sample execution: -

Input:
Case 1 :
Enter the size of array : 5
Elements of array :
1 2 3 4 5
key = 3
Output:	key element 3  is found at 3rd position

Case 2 :
Enter the size of array : 5
Elements of array :
1 2 3 4 5
key  : 25
Output:	key element 25  is  not found


#########################################_Program_begins_from_here_######################################### */


#include "main.h"

/* Main Function */
int main()
{
    /* Declaring the variables */
    data_t option, res, key, size;

    /* Reading the number of elements from the user */
    printf("Enter the size of an array\n");
    scanf("%d", &size);

    data_t arr[size];

    /* Reading the elements */
    printf("Enter the elements of an array\n");
    for (int i = 0; i < size; i++)
    {
	scanf("%d", &arr[i]);
    }

    /* reading the key from the user */
    printf("Enter the key to search\n");
    scanf("%d", &key);

    /* Calling the function to search the element */
    if ((res = binarySearch_recursive(arr, size, key, 0, size - 1)) == DATA_NOT_FOUND)
    {
	printf("INFO : Key not found\n");
    }
    else
    {	
	printf("INFO : Key found at the position %d\n", res);
    }

    return 0;
}
