/*


Name: Harsharaj Nath
Date of Submission: 08-11-22
Description: WAF to sort the given single linked list


Sample execution: -

SL List → 50 → 40 → 30 → 20 → 10

Output → 10 → 20 → 30 → 40 → 50


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    /* variable declaration */
    int option, data, key;

    /* initialize the header to NULL */
    Slist *head = NULL;

    printf("1. Insert at last\n2. Sort list\n3. Print list\n4. Exit\nEnter your choice : ");

    while (1)
    {
	/* ask user options */
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     /* insert at last */

		printf("Enter the number that you want to insert at last: ");
		scanf("%d", &data);

		/* insert_at_last function call */
		if (insert_at_last(&head, data) == FAILURE) 
		{
		    printf("INFO : Insert last failed\n");
		}
		break;

	    case 2:     /* sort the list */

		/* Function to sort the link */
		if (sl_sort(&head) == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("INFO : Sorting successfull\n");
		}
		break;

	    case 3:     /* printing the list */

		/* print list function call*/
		print_list(head);
		break;

	    case 4:     /* exit */

		return SUCCESS;

	    default:

		printf("Enter proper choice !!\n");
		break;
	}
    }

    return SUCCESS;
}
