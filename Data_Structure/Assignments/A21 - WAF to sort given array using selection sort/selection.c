#include "main.h"

//function for selection sort
data_t selection(data_t *arr, data_t size )
{
    //variable declaration
    int i, current_min, current_item, temp;

    //loop for traversing the array
    for( i = 0; i < size - 1; i++)
    {
	//updating value of current_min with value of i
	current_min = i;

	//current_item is one more than current_min
	//loop for comparaing the elements
	for( current_item = i+1; current_item < size; current_item++ )
	{
	    //if current min is greater than current item
	    if(arr[current_item] < arr[current_min])
	    {
		//current min is updated with the value of current item
		current_min = current_item;
	    }
	}

	//if current min is not equal to i (i.e current min value is changed)
	if(current_min != i)
	{
	    //swap arr[i] and arr[current_min]
	    temp = arr[i];
	    arr[i] = arr[current_min];
	    arr[current_min] = temp;
	}
    }
}
