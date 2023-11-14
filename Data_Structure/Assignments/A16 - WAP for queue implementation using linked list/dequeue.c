#include "queue.h"

//function to dequeue data from the queue using linked list
int dequeue(Queue_t **front, Queue_t **rear)
{
    //if no node present
    if(*front == NULL)
    {
	return FAILURE;
    }

    //if queue is empty
    if(*front == *rear)
    {
	*front = NULL;
	*rear = NULL;
    }
    else
    {
	//creating local reference pointer
	Queue_t *temp = *front;

	//updating front pointer with next node
	*front = (*front) -> link;

	//deallocating the memory
	free(temp);

	//updating the rear pointer link with the first node
	(*rear) -> link = *front;
    }

    return SUCCESS;
}
