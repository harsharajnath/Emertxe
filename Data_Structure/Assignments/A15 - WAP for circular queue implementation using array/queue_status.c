#include "queue.h"

//function to check if queue is full
int IsQueueFull(Queue_t *q)
{
    //if count is equal to capacity then the queue is full
    if(q -> count == q -> capacity)
    {
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}

//functiion to check if queue is empty
int IsQueueEmpty(Queue_t *q)
{
    //if count us 0 then the queue is empty
    if(q -> count == 0)
    {
	return SUCCESS;
    }
    else
    {
	return FAILURE;
    }
}
