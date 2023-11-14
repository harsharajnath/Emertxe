/*


Name: Harsharaj Nath
Date of Submission: 30-10-22
Description: Single Linked List basic operations

Implement the functions given below :-
1.insert_at_first(head, data)
2.insert_at_last(head, data)
3.delete_first(head)
4.delete_last(head)
5.delete_list(head)
6.find_node(head, data)


Sample execution: -

Test Case 1: insert_at_first

Cases :
List empty, data = 10
head = NULL , After inserting data into list, list contains
10 → NULL

List not empty, data 40
10 → 20 → 30 → NULL, After inserting 40 into list
40 → 10 → 20 → 30 → NULL

Test Case 2: insert_at_last

Cases : 
List empty
List not empty
1. List empty – Update the head with new node address.
2. List not empty – Traverse to the last node and establish the link between last node and new node.

Test Case 3: delete_first

Cases : 
List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
List not empty → Update the head with next node address, delete the first node.
Example :
head → 10 → 20 → 30 → 40 → 50 → NULL
head 10 → 20 → 30 → 40 → 50 → NULL
head → 20 → 30 → 40 → 50 → NULL

Test Case 4: delete_last

Cases :
List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
List not empty → Traverse to the last node, update the previous node address and delete the last node.

Test Case 5: delete_list

Cases :
List empty → Return LIST_EMPTY (in empty list node can’t be deleted)
List not empty → Delete all nodes one by one.

Test Case 6: find_node

Cases : 
List empty → Return LIST_EMPTY (in empty list can’t search data)
List not empty
1. Data found
2. Data not found

→ Traverse through the list to search the data
→ If data found return DATA_FOUND
→ Else return DATA_NOT_FOUND


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

// global variable
int pos;

int main()
{
    // delcaration
    int option, data, key, status;


    Slist *head = NULL;     //initialize the header to NULL

    printf("1. Insert last\n2. Insert first\n3. Delete Last\n4. Delete first\n5. Delete list\n6. Find node\n7. Print list\n8. Exit\nEnter your choice : \n");

    while(1)
    {
	//taking user input for the options
	scanf("%d", &option);

	switch (option)
	{
	    case 1:     //insert the element at last

		printf("Enter the number that you want to insert at last: ");
		scanf("%d", &data);     //reading the data from user


		//insert_at_last function call
		if (insert_at_last(&head, data) == FAILURE)     //pass by reference
		{
		    printf("INFO : Insertion Failure\n");
		}
		break;

	    case 2:     //insert the element at first

		printf("Enter the element you have to insert at the first : ");
		scanf("%d", &data);     //reading the data from user

		if (insert_at_first(&head, data) == FAILURE)     //pass by reference
		{
		    printf("INFO : Insertion Failure\n");
		}
		break;

	    case 3:     //delete the last node

		if (sl_delete_last(&head) == LIST_EMPTY)
		{
		    printf("INFO : Delete last Failure\nList is empty\n");
		}
		else
		{
		    printf("INFO : Delete last successfull\n");
		}
		break;

	    case 5:     //delete the list

		if (sl_delete_list(&head) == LIST_EMPTY)
		{
		    printf("INFO : Delete list Failure\nList is empty\n");
		}
		else
		{
		    printf("INFO : Delete list Successfull\n");
		}
		break;

	    case 4:     //delete the first node

		if (sl_delete_first(&head))
		{
		    printf("INFO : Delete first Failure\n List is empty\n");
		}
		else
		{
		    printf("INFO : Delete first successfull\n");
		}
		break;

	    case 6:     //find a node

		pos = 0;    //reset pos

		printf("Enter the key to find : ");
		scanf("%d", &key);     //reading the data from user

		status = find_node(head, key);      //storing return value in a variable

		if ( status == LIST_EMPTY || status == DATA_NOT_FOUND )
		{
		    printf("INFO : Failure\nList is empty or Key not found\n");
		}
		else
		{
		    printf("%d found in the list at the position %d\n", key, pos);
		}
		break;

	    case 7:     //print the list

		//print list function call
		print_list(head);
		break;

	    case 8:     //exiting the program

		exit(0);
		break;

	    default:        //default case

		printf("Enter proper choice !!\n");
		break;
	}
    }

    return 0;
}
