#include"hash.h"

/* Function to delete the entire Hash Table */
int destroy_HT(hash_t *arr, int size)
{
    //creating a local reference pointer
    hash_t *temp_1;
    hash_t *temp_2;

    for(int i = 0; i < size; i++)
    {
	//if array value is not -1
	if(arr[i].value != -1)
	{
	    //storing the link contained in array index in temp_1 pointer 
	    temp_1 = arr[i].link;

	    //updating the value to -1
	    arr[i].value = -1;

	    //updating array index link to NULL
	    arr[i].link = NULL;
	}

	//traversing till the end and deleteing each node
	while(temp_1 != NULL)
	{
	    //storing link of temp_1 in temp_2
	    temp_2 = temp_1 -> link;

	    //deallocating the memory
	    free(temp_1);

	    //updating temp_1
	    temp_1 = temp_2;
	}
    }

    return SUCCESS;
}
