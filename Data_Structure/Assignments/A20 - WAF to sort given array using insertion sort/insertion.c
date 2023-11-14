#include "main.h"

//function for insertion sort
data_t insertion(data_t *arr, data_t size)
{
    //variable declaration
    int key;
    int i, j;

    //loop for traversing the array
    for ( i = 1; i < size; i++ )
    {
	//take one by one element as key value staring from 2nd element
	key = arr[i];

	//j starts from 1st element and is one less than value of i
	j = i - 1;

	//if the element is greater than key
	while( j >= 0 && arr[j] > key)
	{
	    //shifting the element by one place towards right
	    arr[j+1] = arr[j];

	    //decrementing the j value
	    j = j - 1;
	}

	//place the key in its correct position
	arr[j+1] = key;
    }
}
