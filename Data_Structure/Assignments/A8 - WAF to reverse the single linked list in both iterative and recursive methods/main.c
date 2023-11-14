/*


Name: Harsharaj Nath
Date of Submission: 08-11-22
Description: WAF to reverse the single linked list in both iterative and recursive methods


Sample execution: -

SL List → 50 → 40 → 30 → 20 → 10

Output → 10 → 20 → 30 → 40 → 50


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    /* variable declaration */
    int option, data;

    /* initialize the header to NULL */
    Slist *head = NULL;

    printf("1. Insert the element\n2. Print list\n3. Reverse Iterative\n4. Reverse Recusive\n5. Exit\nEnter your choice : ");
    while(1)
    {
	/*ask user options*/
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
		    printf("INFO : Insert at last failure\n");
		}
		break;

	    case 2:     /* printing the list */

		/* print list function call*/
		print_list(head);
		break;

	    case 3:     /* reverse list by iterative method */

		if (reverse_iter(&head) == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("INFO : Reverse iterative successfull\n");
		}
		break;

	    case 4:     /* reverse list by recursive method */

		if (reverse_recursive(&head) == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("INFO : Reverse recursive successfull\n");
		}
		break;

	    case 5:     /* exit */

		return SUCCESS;

	    default:

		printf("Enter proper choice !!\n");
	}
    }

    return SUCCESS;
}
