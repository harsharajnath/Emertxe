#include "queue.h"

//function to enqueue data to the queue using linked list
int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    //create node
    Queue_t *new = malloc(sizeof(Queue_t));

    //error check
    //if new node pointer is pointing to some address or NULL
    if(new == NULL)
    {
	return FAILURE;
    }

    //update node data
    new -> data = data;

    //if no node present
    if(*front == NULL)
    {
	//updating front and rear pointer to point to new node
	*front = new;
	*rear = new;
    }
    else
    {
	//adding new node at the end
	(*rear) -> link = new;

	//updating the rear pointer
	*rear = new;
    }

    //updating link of new node to point to the first node
    new -> link = *front;

    return SUCCESS;
}
