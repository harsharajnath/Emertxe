#include"hash.h"

/* Function to search for data in Hash Table */
int search_HT(hash_t *arr, int data, int size)
{
    //variable declaration   
    int index;

    //updating the index value
    index = data % size;

    //if data found in the primary hash table
    if(arr[index].value == data)
    {
	return SUCCESS;
    }

    /* else */
    //creating a local reference pointer for traversing
    hash_t *temp = arr[index].link;

    //traversing till the end
    while(temp != NULL)
    {
	//if data found
	if(temp -> value == data)
	{
	    return SUCCESS;
	}

	temp = temp -> link;
    }

    return DATA_NOT_FOUND;
}
