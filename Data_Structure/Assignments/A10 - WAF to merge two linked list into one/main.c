/*


Name: Harsharaj Nath
Date of Submission: 08-11-22
Description: WAF to merge two linked list into one


Sample execution: -

Input: 
List – 1    30 → 10 → 50
List – 2    20 → 5 → 35

Output: 5 → 10 → 20 → 30 → 35 → 50


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    /* variable declaration */
    Slist *head1 = NULL;
    Slist *head2 = NULL;
    int choice, data, temp = 0;

    printf("1. Insert at  List 1\n2. Insert at list 2\n3. Print list\n4. Sorted merge\n5. Exit\nEnter your choice: ");

    while (1)
    {
	/* call function display menu */
	scanf("%d", &choice);

	switch (choice)
	{

	    case 1:     /* insert element at last for LL1 */

		printf("Enter the data to be inserted at list 1 : ");
		scanf("%d", &data);

		if (insert_at_last(&head1, data) == FAILURE)
		    printf("INFO: Failed to Inserting the new data at last..try again\n");
		break;

	    case 2:     /* insert element at last for LL2 */

		printf("Enter the data to be inserted at list 2 : ");
		scanf("%d", &data);

		if (insert_at_last(&head2, data) == FAILURE)
		    printf("INFO: Failed to Inserting the new data at last..try again\n");
		break;

	    case 3:     /* printing the list */

		if (temp == 0)
		{
		    printf("\nList 1 -> ");
		    print_list(head1); // print list_1
		    printf("\n\nList 2 -> ");
		    print_list(head2); // print list_2
		    break;
		}
		else
		    print_list(head1);
		break;

	    case 4:     /* merge and sort the list */

		if (sorted_merge(&head1, &head2) == SUCCESS)
		{
		    temp = 1;
		    printf("INFO : Sorted merge Successfull\n");
		}
		else
		    printf("INFO : Both list are Empty\n");

		break;

	    case 5 :    /* exit */

		return SUCCESS;

	    default:

		printf("\nEnter the proper choice\n");
	}
    }

    return 0;
}
