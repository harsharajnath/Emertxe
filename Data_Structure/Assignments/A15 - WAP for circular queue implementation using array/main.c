/*


Name: Harsharaj Nath
Date of Submission: 15-11-22
Description: WAP for circular queue implementation using array

Implement functions given below :
1. Enqueue(queue, data) 
2. Dequeue(queue) 
3. Print_queue(queue)

Sample execution: -

1. Enqueue : 
Inputs : queue → Pointer contains structure variable 
data → Data to be added. 
Cases : 
1. Queue Full → Return QUEUE_FULL.
2. Queue not full → Add data into queue. 
2. Dequeue : 
Inputs : queue → Pointer contains structure variable 
Cases : 
1. Queue Empty → Return QUEUE_EMPTY. 
2. Queue Not Empty → Delete the data from the front end.

Sample Output:
Assume, data's 40, 30, 20, 10 are inserted in queue, output should be
Front -> 10 20 30 40 <- Rear


#########################################_Program_begins_from_here_######################################### */


#include "queue.h"

//function to create a queue
int create_queue(Queue_t *q, int size)
{
    //allocating memory dynamically
    q -> Que = malloc(sizeof(int) * size);

    //checking if memory allocation is successful or not
    if(q -> Que == NULL)
    {
	return FAILURE;
    }

    //initializing the variables
    q -> capacity = size;
    q -> front = -1;
    q -> rear = -1;
    q -> count = 0;

    return SUCCESS;
}

int main()
{
    //variable declaration
    Queue_t q;
    int size;
    char ch;
    int choice, data;

    //reading size of queue from user
    printf("Enter the size of the queue : ");
    scanf("%d", &size);

    //creating a queue
    if (create_queue(&q, size) == FAILURE)
    {
	printf("INFO : Queue not created\n");
	return FAILURE;
    }

    printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");

    while (1)
    {
	//reading the choice from user
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		/* Function to Enqueue the Queue */
		printf("Enter the element you want to insert : ");
		scanf("%d", &data);
		if (enqueue(&q, data) == FAILURE)
		{
		    printf("INFO : Queue full\n");
		}
		break;

	    case 2:
		/* Function to dequeueue the queue */
		if (dequeue(&q) == FAILURE)
		{
		    printf("INFO : Queue is empty\n");
		}
		else
		{
		    printf("INFO : Dequeue successfull\n");
		}
		break;

	    case 3:
		/* Function to print the queue */
		print_queue(q);
		break;

	    case 4:
		/* exit */
		return SUCCESS;

	    default:
		printf("Invalid option !!!\n");
	}
    }
}
