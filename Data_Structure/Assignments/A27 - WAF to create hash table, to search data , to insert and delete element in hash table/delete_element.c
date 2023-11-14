#include"hash.h"

/* Function to delete an element from the Hash Table */
int delete_element(hash_t *arr, int data, int size)
{
    //variable declaration   
    int index;

    //updating the index value
    index = data % size;

    //if data found in the primary hash table
    if(arr[index].value == data)
    {
	//if link of the array index is NULL
	if(arr[index].link == NULL)
	{
	    //delete the data
	    arr[index].value = -1;

	    return SUCCESS;
	}
	else if(arr[index].link != NULL)
	{
	    //creating a local reference pointer pointing to link of array index
	    hash_t *temp = arr[index].link;

	    if(temp -> link == NULL)
	    {
		//updating array index value and link with that of temp
		arr[index].value = temp -> value;
		arr[index].link = temp -> link;

		//deallocate the memory
		free(temp);

		return SUCCESS;
	    }
	}
    }
    //if data not found in the primary hash table
    else
    {
	//creating local reference pointers
	hash_t *temp = arr[index].link;
	hash_t *temp_prev;

	//traversing till the end
	while(temp != NULL)
	{
	    //if data found
	    if(temp -> value == data)
	    {
		//if data found in 1st node
		if(temp == arr[index].link)
		{
		    //update the array index link with the temp link
		    arr[index].link = temp -> link;

		    //deallocate the memory
		    free(temp);

		    return SUCCESS;
		}
		else
		{
		    //update link of previous node with the link of temp node
		    temp_prev -> link = temp -> link;

		    //deallocate the memory
		    free(temp);

		    return SUCCESS;
		}
	    }

	    temp_prev = temp;
	    temp = temp -> link;
	}
    }

    return DATA_NOT_FOUND;
}
