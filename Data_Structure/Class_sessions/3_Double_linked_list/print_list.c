#include "dll.h"

void print_list(Dlist *head)
{
    if(head == NULL)
    {
	printf("No node to print\n");
    }
    else
    {
	while(head)
	{
	    printf("%d-->", head -> data);
	    head = head -> next;
	}

	if(head == NULL)
	{
	    printf("NULL");
	}

	printf("\n");
    }
}
