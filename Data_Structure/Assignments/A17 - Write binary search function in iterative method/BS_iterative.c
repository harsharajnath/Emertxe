#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    //variable initialization
    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high)
    {
	//finding the middle element
	mid = (low + high) / 2;

	//if middle element is the key
	if(arr[mid] == key)
	{
	    return mid;
	}
	//if key is less than middle element
	else if ( key < arr[mid])
	{
	    //updating the high with new value
	    high = mid - 1;
	}
	//if key is greater than middle element
	else
	{
	    //updating the low wiith new value
	    low = mid + 1;
	}
    }

    //if key not found
    return DATA_NOT_FOUND;
}
