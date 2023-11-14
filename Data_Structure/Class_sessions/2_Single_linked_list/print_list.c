#include "sll.h"

void print_list(Slist *head)
{
    if(head == NULL)
    {
	printf("No node to print\n");
    }
    else
    {
	while(head != NULL)
	{
	    printf("%d-->", head -> data);
	    head = head -> link;
	}

	if(head == NULL)
	{
	    printf("NULL");
	}

	printf("\n");
    }
}
