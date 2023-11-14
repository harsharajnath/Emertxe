#include "main.h"

//function for bubble sort
data_t bubble(data_t *arr, int size )
{
    //variable declaration
    int temp;

    //loop for traversing the array
    for(int i = 0; i < size - 1; i++)
    {
	//loop for comparaing the elements
	for(int j = 0; j < size - 1 - i; j++)
	{
	    //if 1st element is greater than 2nd element
	    if(arr[j] > arr[j+1])
	    {
		//swap the two elements
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
	    }
	}
    }
}
