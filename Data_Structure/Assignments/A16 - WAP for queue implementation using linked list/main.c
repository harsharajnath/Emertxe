/*


Name: Harsharaj Nath
Date of Submission: 16-11-22
Description: WAP for queue implementation using linked list

Implement functions given below :
1. Enqueue(front, rear, data) 
2. Dequeue(front, rear) 
3. Print_queue(front) 

Sample execution: -

1. Enqueue :
Inputs :
front → pointer to first node 
rear → pointer to last node 
data → Data to be added.
Cases : 
Queue Empty → Update front and rear with new node
Queue not Empty → Add data at rear end.

2. Dequeue :
Inputs : 
Front → pointer to first node 
rear → pointer to last node 
Cases : 
Queue Empty → Return QUEUE_EMPTY.
Queue Not Empty → Delete the data from the front end (free node in LL).


#########################################_Program_begins_from_here_######################################### */


#include "queue.h"

int main()
{
    //initializing the pointers
    Queue_t *front = NULL, *rear = NULL;

    //variable declaration
    int choice, data;

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
		if (enqueue(&front, &rear, data) == FAILURE)
		{
		    printf("INFO : Queue full\n");
		}
		break;

	    case 2:
		/* Function to dequeueue the queue */
		if (dequeue(&front, &rear) == FAILURE)
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
		print_queue(front, rear);
		break;

	    case 4:
		/* exit */
		return SUCCESS;

	    default:
		printf("Invalid option !!!\n");
	}
    }
}
