/*


Name: Harsharaj Nath
Date of Submission: 08-11-22
Description: WAP to remove duplicates in a SLL


Sample execution: -

SL List → 1 → 2 → 4 → 2 → 5 → 4 → 3 → 1 → 2 

Output → 1 → 2 → 4 → 5 → 3


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    /* variable declaration */
    int option, data;

    /* initialize the header to NULL */
    Slist *head = NULL; 

    printf("\n1. To insert the last element\n2. To print the list\n3. To remove the duplicates\n4. Exit\nEnter your option : ");

    while(1)
    {
	/* ask user options */
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     /* insert at last */

		printf("Enter the number that you want to insert at last: ");
		scanf("%d", &data);

		/* insert_at_last function call */
		/* pass by reference */
		if (insert_at_last(&head, data) == FAILURE)
		{
		    printf("INFO : insert last failure\n");
		}
		break;

	    case 2:     /* printing the list */

		/* print list function call */
		print_list(head);
		break;

	    case 3:     /* remove duplicates */

		if (remove_duplicates(&head) == FAILURE)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("INFO : Duplicates are removed Successfully\n");
		}
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
