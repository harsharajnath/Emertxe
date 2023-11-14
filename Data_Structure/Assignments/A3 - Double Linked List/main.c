/*


Name: Harsharaj Nath
Date of Submission: 12-11-22
Description: Double Linked List

Implement functions given below.
1. dll_insert_first(head, tail, data)
2. dll_insert_last(head, tail, data)
3. dll_delete_first(head, tail)
4. dll_delete_last(head, tail)
5. dll_delete_list(head, tail)

Sample execution: -

1. dll_insert_at_first :
head → 10 ← tail

2. dll_Insert_at_last :
head → 10 → 20 → 30 → 40 → 50 ← tail

3. dll_delete_first :
head → 10 → 20 → 30 → 40 ← tail

4. dll_delete_last :
head → 10 → 20 → 30 ← tail

5. delete_list :
INFO : Delete list Successful


#########################################_Program_begins_from_here_######################################### */


#include "dll.h"

int main()
{
    //variable declaration
    int option, data;

    Dlist *head = NULL; //initialize the header to NULL
    Dlist *tail = NULL; //initialize the tail to NULL

    printf("\n1. Dll Insert last\n2. Dll Insert first\n3. Dll delete Last\n4. Dll delete first\n5. Dll delete list\n6. Print list\n7. Exit\nEnter your option: ");

    while (1)
    {
	/*ask user options*/
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     /*To insert the element at last */

		printf("Enter the number that you want to insert at last: ");
		scanf("%d", &data);

		/*insert_at_last function call*/
		if (dl_insert_last(&head, &tail, data) == FAILURE) //pass by reference
		{
		    printf("INFO : Insertion Failure\n");
		}
		break;

	    case 2:     /*To insert the element at first */

		printf("Enter the element you have to insert at the first : ");
		scanf("%d", &data);
		if (dl_insert_first(&head, &tail, data) == FAILURE)
		{
		    printf("INFO : Insertion Failure\n");
		}
		break;

	    case 3:     /* Delete a last link*/

		if (dl_delete_last(&head, &tail) == FAILURE)
		{
		    printf("INFO : Delete last Failure, List is empty\n");
		}
		else
		{
		    printf("INFO : Delete last Successfull\n");
		}
		break;

	    case 4:     /*To delete first node */

		if (dl_delete_first(&head, &tail) == FAILURE)
		{
		    printf("INFO : Delete first Failure, List is empty\n");
		}
		else
		{
		    printf("INFO : Delete first Successfull\n");
		}
		break;

	    case 5:     /* Delete list */

		if (dl_delete_list(&head, &tail) == FAILURE)
		{
		    printf("INFO : Delete list Failure, List is empty\n");
		}
		else
		{
		    printf("INFO : Delete list Successfull\n");
		}
		break;

	    case 6:     /* printing the list */

		/* print list function call*/
		print_list(head);
		break;

	    case 7:     /* exit */ 

		return SUCCESS;

	    default:

		printf("Enter proper choice !!\n");
		break;
	}
    }

    return SUCCESS;
}
