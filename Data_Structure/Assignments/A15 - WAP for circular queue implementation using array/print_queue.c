#include "queue.h"

/* Function to print the Queue */
int print_queue(Queue_t q)
{

    /* Checking the queue is empty or not */
    if (IsQueueEmpty(&q) == SUCCESS)
    {
	printf("INFO : Queue is empty\n");
	return FAILURE;
    }

    printf("Front -> ");
    do
    {
	printf("%d ", q.Que[q.front]);
	q.front = (q.front + 1) % q.capacity;
	/* Printing the queue till it will reaches end */	
    }while (--(q.count));

    printf("<- Rear\n");

    /* Returning SUCCESS */
    return SUCCESS;
}
