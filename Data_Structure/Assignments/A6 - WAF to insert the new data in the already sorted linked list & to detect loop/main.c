/*


Name: Harsharaj Nath
Date of Submission: 11-11-22
Description: WAF to insert the new data in the already sorted linked list & to detect
whether the given linked list is ending with loop or not


Sample execution: -

SL List → 10 → 20 → 30 → 40 → 50

data = 45

Output → 10 → 20 → 30 → 40 → 45 → 50


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    /* variable declaration */
    int option, data, ret;

    /* initialize the header to NULL */
    Slist *head = NULL;

    printf("1. Insert sorted\n2. Find loop\n3. Create loop\n4. Print list\n5. Exit\nEnter Your choice : ");
    while (1)
    {
	/* ask user options */
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     /* insert the data */

		printf("Enter the data to be inserted : ");
		scanf("%d", &data);
		if (insert_sorted(&head, data) == -1)
		{
		    printf("INFO : Insert sorted failure\n");
		}
		break;

	    case 2:     /* Function to find the loop */

		if ((ret = find_loop(head)) == LOOP_NOT_FOUND)
		{
		    printf("INFO : Loop is not found\n");
		}
		else if (ret == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		    printf("INFO : Loop found\n");
		break;

	    case 3:     /* create a loop */

		printf("Enter a data to create the loop : ");
		scanf("%d", &data);

		/* insert_at_last function call */
		/* pass by reference */
		if ((ret = create_loop(&head, data)) == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else if (ret == DATA_NOT_FOUND)
		{
		    printf("INFO : %d not found at the list\n", data);
		}
		else
		{
		    printf("INFO : Loop created successfully\n");
		}
		break;

	    case 4:     /* printing the list */

		/* print list function call*/
		print_list(head);
		break;

	    case 5:     /* exit */

		return SUCCESS;

	    default:

		printf("Enter proper choice !!\n");
		break;
	}
    }

    return SUCCESS;
}
