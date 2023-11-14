#include "main.h"

//function for merging the sub arrays while sorting
void merge(int *array, int size, int *Lsa, int mid1, int *Rsa, int mid2)
{ 
    //variable initialization
    int i = 0;      //for left sub array
    int j = 0;      //for right sub array
    int k = 0;      //for merged array


    while((i < mid1) && (j < mid2))
    {
	//if left sub array value is less than rigt sub array value
	if(Lsa[i] < Rsa[j])
	{
	    //update array with left sub array value
	    array[k] = Lsa[i];

	    //incrementing i and k
	    i++;
	    k++;
	}
	else
	{
	    //update array with right sub array value 
	    array[k] = Rsa[j];

	    //incrementing j and k
	    j++;
	    k++;
	}
    }

    /* BELOW CONDITIONS ARE FOR ELIMINATING ODD OR EVEN SITUATION */

    //copy remaining left sub array elements(if any) to the merged array
    while(i < mid1)
    {
	array[k] = Lsa[i];
	i++;
	k++;
    }

    //copy remaining right sub array elements(if any) to the merged array
    while(j < mid2)
    {
	array[k] = Rsa[j];
	j++;
	k++;
    }

    //free the memory given for left and right sub arrays
    free(Lsa);
    free(Rsa);
}
