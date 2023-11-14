#include "main.h"

/* Function to sort the array in quick sort method */
int quick_sort( int *arr, int first, int last )
{
    //variable declaration
    int index;

    //base condition for the recursive calls
    if(first < last)
    {
	//storing the pivot element position
	index = partition(arr, first, last);

	//left partition
	quick_sort(arr, first, index - 1);

	//right partition
	quick_sort(arr, index + 1, last);
    }
}
