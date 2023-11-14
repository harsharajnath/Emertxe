#include "sll.h"

/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{
    //check for list empty or not
    if(head == NULL)
    {
	return LIST_EMPTY;
    }

    //if entered postion is 0
    if(pos == 0)
    {
	return FAILURE;
    }

    //create local reference pointer
    Slist *temp = head;
    Slist *nth_last_node = head;

    while(temp != NULL)     //looping till the end of list
    {
	temp = temp -> link;      //incrementing the temp pointer
	if(pos != 0)		//while the required position does not become zero
	{
	    pos--;		//decrement the pos
	}
	else
	{
	    nth_last_node = nth_last_node -> link;      //updating the nth last node pointer
	}
    }

    if(pos != 0)	//even after the loop, if pos is not 0
    {
	return FAILURE;
    }
    else
    {
	*data = nth_last_node -> data;      //storing the data of nth last node
    }

    return SUCCESS;
}
