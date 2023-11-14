#include "dll.h"

int main()
{
    system("clear");
    Dlist *head = NULL;
    Dlist *tail = NULL;
    int choice;
    int status;
    int data;
    int g_data;
    int n_data;

    int tail_data;

    printf("Options:\n");
    printf("1.Insert at last\n");
    printf("2.Insert after\n");
    printf("3.Insert at first\n");
    printf("4.Insert before\n");
    printf("5.Delete at first\n");
    printf("6.Delete at last\n");
    printf("7.Delete list\n");
    printf("8.Print list\n");
    printf("9.Print tail data\n");
    printf("10.Exit\n");

    while(1)
    {
	printf("\nEnter your choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		printf("Enter the data to insert at last: ");
		scanf("%d", &data);

		if(insert_at_last(&head, &tail, data) == FAILURE)
		{
		    printf("Failed: Inserting the new data at last\nTry again...\n");
		}
		else
		{
		    printf("Data added Successfully\n");
		}

		break;

	    case 2:
		printf("Enter the node after which data to be inserted: ");
		scanf("%d", &g_data);

		printf("Enter the new data to be inserted: ");
		scanf("%d", &n_data);

		status = insert_after(&head, &tail, g_data, n_data);

		if(status == FAILURE)
		{
		    printf("Failed: Inserting the new data\nTry again...\n");
		}
		else if(status == LIST_EMPTY)
		{
		    printf("List Empty\n");
		}
		else if(status == DATA_NOT_FOUND)
		{
		    printf("Data not found\n");
		}
		else
		{
		    printf("Data added Successfully\n");
		}

		break;

	    case 3:
		printf("Enter the data to insert at first: ");
		scanf("%d", &data);

		if(insert_at_first(&head, &tail, data) == FAILURE)
		{
		    printf("Failed: Inserting the new data at first\nTry again...\n");
		}
		else
		{
		    printf("Data added Successfully\n");
		}

		break;

	    case 4:
		printf("Enter the node before which data to be inserted: ");
		scanf("%d", &g_data);

		printf("Enter the new data to be inserted: ");
		scanf("%d", &n_data);

		status = insert_before(&head, g_data, n_data);

		if(status == FAILURE)
		{
		    printf("Failed: Inserting the new data\nTry again...\n");
		}
		else if(status == LIST_EMPTY)
		{
		    printf("List Empty\n");
		}
		else if(status == DATA_NOT_FOUND)
		{
		    printf("Data not found\n");
		}
		else if(status == SUCCESS)
		{
		    printf("Data added Successfully\n");
		}

		break;

	    case 5:
		status = delete_at_first(&head, &tail);

		if(status == FAILURE)
		{
		    printf("Failed: Deleting the data\nTry again...\n");
		}
		else if(status == LIST_EMPTY)
		{
		    printf("List Empty\n");	
		}
		else if(status == SUCCESS)
		{
		    printf("Data deleted Successfully\n");
		}

		break;

	    case 6:
		status = delete_at_last(&head, &tail);

		if(status == FAILURE)
		{
		    printf("Failed: Deleting the data\nTry again...\n");
		}
		else if(status == LIST_EMPTY)
		{
		    printf("List Empty\n");	
		}
		else if(status == SUCCESS)
		{
		    printf("Data deleted Successfully\n");
		}

		break;

	    case 7:
		status = delete_list(&head, &tail);

		if(status == FAILURE)
		{
		    printf("Failed: Deleting the list\nTry again...\n");
		}
		else if(status == LIST_EMPTY)
		{
		    printf("List Empty\n");
		}
		else if(status == SUCCESS)
		{
		    printf("List deleted Successfully\n");
		}

		break;


	    case 8:
		print_list(head);
		break;

	    case 9:
		if(tail != NULL)
		{
		    tail_data = tail -> data;
		    printf("Tail data is: %d\n", tail_data);
		}
		else
		{
		    printf("List empty\n");
		}

		break;

	    case 10:
		exit(0);

	    default:
		printf("Invalid choice...try again!!\n");
		break;
	}
    }

    return 0;
}
