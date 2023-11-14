#include"hash.h"

/* Function to insert data into Hash Table */
int insert_HT(hash_t *arr, int element, int size)
{
    //variable declaration   
    int index;

    //updating the index value
    index = element % size;

    //if hash table's value field is empty, store the element directly
    if(arr[index].value == -1)
    {
	arr[index].value = element;
	return SUCCESS;
    }

    /* else */
    //creating a new node
    hash_t *new = malloc(sizeof(hash_t));

    //checking if memory is allocated
    if(new == NULL)
    {
	return FAILURE;
    }

    //updating new pointer's data and link
    new -> index = index;
    new -> value = element;
    new -> link = NULL;

    //if hash table's link field is NULL, add the new node
    if(arr[index].link == NULL)
    {
	//update link with new node address
	arr[index].link = new;
	return SUCCESS;
    }

    /* else */
    //creating a local reference pointer for traversing
    hash_t *temp = arr[index].link;

    //traversing till the end
    while(temp -> link != NULL)
    {
	temp = temp -> link;
    }

    //update link with new node address
    temp -> link = new;

    return SUCCESS;
}
