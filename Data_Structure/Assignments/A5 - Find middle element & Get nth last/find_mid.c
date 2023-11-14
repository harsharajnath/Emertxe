#include "sll.h"

/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{
    //check for list empty or not
    if(head == NULL)
    {
	return LIST_EMPTY;
    }

    //create local reference pointer
    Slist *fast = head;		//move two nodes at a time
    Slist *slow = head;		//moves one node at a time

    while(fast != NULL && fast -> link != NULL)     //looping till the end of list
    {
	fast = (fast -> link) -> link;		//moving two nodes ahead
	slow = slow -> link;		//moving one node ahead
    }

    *mid = slow -> data;		//storing data of slow pointer to mid

    return SUCCESS;
}
