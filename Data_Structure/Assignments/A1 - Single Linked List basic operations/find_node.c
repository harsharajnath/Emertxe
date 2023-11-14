#include "sll.h"

int find_node(Slist *head, data_t data)
{
    extern int pos;

    //check for list empty or not
    if(head == NULL)
    {
	return LIST_EMPTY;
    }

    //if only one node present
    if(((head) -> link) == NULL)
    {
	if((head -> data) == data)
	{
	    pos++;      //incrementing the postion
	    return DATA_FOUND;
	}
	else
	{
	    return DATA_NOT_FOUND;
	}
    }


    //create local reference pointer
    Slist *temp = head;


    //traversing through the list till last node
    while(temp != NULL)
    {
	if(temp -> data == data)	//if data matched
	{
	    pos++;      //incrementing the postion
	    return DATA_FOUND;
	}
	else
	{
	    temp = temp -> link;	//increment the temp pointer
	    pos++;      //incrementing the postion
	}
    }

    if(temp == NULL)
    {
	return DATA_NOT_FOUND;
    }
}
