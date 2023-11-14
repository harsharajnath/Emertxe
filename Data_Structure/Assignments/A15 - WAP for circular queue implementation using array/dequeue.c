#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    //checking if queue is empty
    if(IsQueueEmpty(q) == SUCCESS)
    {
	return FAILURE;
    }

    //incrementing the front variable
    q -> front = (q -> front + 1) % (q -> capacity);

    //decrementing the count
    --(q -> count);

    return SUCCESS;
}
