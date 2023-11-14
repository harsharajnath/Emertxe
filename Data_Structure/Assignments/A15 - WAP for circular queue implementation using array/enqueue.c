#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    //checking if queue is full
    if(IsQueueFull(q) == SUCCESS)
    {
	return FAILURE;
    }

    //updating the front variable
    if(q -> front == -1)
    {
	q -> front = 0; 
    }

    //updating the rear variable
    q -> rear = (q -> rear + 1) % (q -> capacity);

    //adding the data in the queue
    q -> Que[q -> rear] = data;

    //incrementing the count
    ++(q -> count);

    return SUCCESS;
}
