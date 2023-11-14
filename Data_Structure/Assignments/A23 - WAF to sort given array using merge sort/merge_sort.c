#include "main.h"

//function for merge sort
int merge_sort(int *array, int size)
{
    //variable declaration
    int mid;
    int *Lsa, *Rsa;

    //if array has only one element
    if(size == 1)
    {
	return SUCCESS;
    }
    //if array is empty
    else if( size < 1)
    {
	return FAILURE;
    }

    //initializing the mid value
    mid = size / 2;

    //allocating memory for left sub array
    Lsa = malloc(sizeof(int) * mid);

    //error check
    if(Lsa == NULL)
    {
	return FAILURE;
    }

    //adding the elements from 0 to mid-1 in left sub array
    for(int i = 0; i < mid; i++)
    {
	Lsa[i] = array[i];
    }

    //allocating memory for right sub array
    Rsa = malloc(sizeof(int) * (size - mid));

    //error check
    if(Rsa == NULL)
    {
	return FAILURE;
    }

    //adding the elements from mid to size-1 in right sub array
    for(int i = mid; i < size; i++)
    {
	Rsa[i - mid] = array[i];
    }

    //DIVIDE
    //dividing the array into left and right sub array till one element on each leg
    merge_sort(Lsa, mid);
    merge_sort(Rsa, (size - mid));

    //CONQUER
    //merging the arrays, recurssively while sorting
    merge(array, size, Lsa, mid, Rsa, (size - mid));
}
