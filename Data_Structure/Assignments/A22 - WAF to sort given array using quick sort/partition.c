#include "main.h"

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    //variable initialization
    int pivot = first;      //pivot hold the position of the element to be placed at right position
    int p = first;          //p is initialized to first element position of the partition
    int q = last;           //q is initialized to last element position of the partition

    //while p is less than q
    while(p < q)
    {
	//while array element at postion p is less than or equal to pivot element
	//p can be incremented till it reaches last element position
	while(arr[p] <= arr[pivot]  && p <= last)
	{;
	    //increment p
	    p++;
	}

	//while array element at postion q is greater than pivot element
	while(arr[q] > arr[pivot])
	{
	    //decrement q
	    q--;
	}

	//if position p is less than position q
	if(p < q)
	{
	    //swap the elements present at these position
	    swap(&arr[p], &arr[q]);
	}
    }

    //finally swap the elements present at these positions
    swap(&arr[pivot], &arr[q]);

    /* THE PIVOT ELEMENT IS PLACED IN ITS CORRECT POSITION NOW*/
    /* THEREFORE,
    /*      ELEMENTS PRESENT TO THE LEFT OF THE PIVOT ELEMENT ARE SMALLER THAN THE PIVOT ELEMENT */ 
    /*      ELEMENTS PRESENT TO THE RIGHT OF THE PIVOT ELEMENT ARE GREATER THAN THE PIVOT ELEMENT */ 

    //NOTE: only the array elements were swapped above, not the position value
    // return the pivot element position i.e q
    return q;
}

//function to swap two elements of an array
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
