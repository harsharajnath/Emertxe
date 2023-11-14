#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    //variable declaration
    int mid;

    //base condition for termintion
    if(first > last)
    {
	return DATA_NOT_FOUND;
    }
    else
    {
	//finding the middle element
	mid = (first + last) / 2;

	//if middle element is the key
	if(arr[mid] == key)
	{
	    return mid;
	}
	//if key is less than middle element
	else if ( key < arr[mid])
	{
	    //recursive function call with updated value of last
	    return binarySearch_recursive(arr, size, key, first, mid - 1);
	}
	//if key is greater than middle element
	else
	{
	    //recursive function call with updated value of first
	    return binarySearch_recursive(arr, size, key, mid + 1, last);
	}
    }
}
