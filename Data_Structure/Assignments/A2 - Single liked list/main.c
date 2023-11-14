/*


Name: Harsharaj Nath
Date of Submission: 02-11-22
Description: Single Linked list

Implement the functions given below.
1.insert_after(head, gdata, ndata)
2.insert_before(head, gdata, ndata)
3.delete_element(head, gdata)
4.insert_Nth(head, ndata, n)


Sample execution: -

Test Case 1: insert_after
Cases : 
1.List Empty
2.List Non-Empty
1.Given data present
Example:
If given_data = 40, new_data = 45
Input: 10 → 20 → 30 → 40 → 50
Output: 10 → 20 → 30 → 40 → 45 → 50
2.Given data not present

Test Case 2: insert_before
Cases : 
1.List Empty
2.List Non-Empty
1.Given data present
Example:
If given_data = 40, new_data = 45
Input: 10 → 20 → 30 → 40 → 50
Output: 10 → 20 → 30 → 45 → 40 → 50
2.Given data not present


Test Case 3: delete_element
Cases : 
1.List Empty
2.List Non-Empty
1.Given data present
Example:
If given_data = 40
Input: 10 → 20 → 30 → 40 → 50
Output: 10 → 20 → 30 → 50
2.Given data not present

Test Case 4: insert_Nth
Cases : 
1.List Empty
2.List Non-Empty
1.Given ‘n’th position present
Example:
If n = 3, n_data = 23
Input: 10 → 20 → 30 → 40 → 50
Output: 10 → 20 → 23 → 30 →40 → 50 
2.Given ‘n’th position not present   


#########################################_Program_begins_from_here_######################################### */


#include "sll.h"

int main()
{
    //variable declaration
    int option, ndata, gdata, ret, n;

    Slist *head = NULL; //initialize the header to NULL

    printf("1.Insert at first\n2.Insert after\n3.Insert before\n4.Insert Nth\n5.Delete element\n6.Print list\n7. Exit\nEnter any option : ");

    while(1)
    {
	//ask user options
	scanf("%d", &option);

	switch (option)
	{
	    case 1: // insert at first
		printf("Enter the number you have to insert : ");
		scanf("%d", &ndata);

		if (insert_at_first(&head, ndata) == FAILURE)
		{
		    printf("INFO : Insert first failure\n");
		}
		break;

	    case 2: //insert after
		printf("Enter the value of gdata : ");
		scanf("%d", &gdata);
		printf("Enter the ndata that you want to insert after %d : ", gdata);
		scanf("%d", &ndata);

		//insert_after function call
		if ((ret = sl_insert_after(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
		{
		    printf("INFO : %d is not found at the list\n", gdata);
		}
		else if (ret == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		break;

	    case 3:  //insert before
		printf("Enter the value of gdata : ");
		scanf("%d", &gdata);
		printf("Enter the ndata that you want to insert before %d : ", gdata);
		scanf("%d", &ndata);

		//insert_before function call
		if ((ret = sl_insert_before(&head, gdata, ndata)) == DATA_NOT_FOUND) //pass by reference
		{
		    printf("INFO %d is not found at the list\n", gdata);
		}
		else if (ret == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		break;

	    case 4: //insert nth
		printf("Enter the node number : ");
		scanf("%d", &n);
		printf("Enter the number that you want to insert %dth position : ", n);
		scanf("%d", &ndata);

		//insert_nth function call
		if ((ret = sl_insert_nth(&head, ndata, n)) == POSITION_NOT_FOUND)//pass by reference
		{
		    printf("INFO : %d Position not found\n", n);
		}
		else if (ret == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("%d is successfully inserted at the position %d\n", ndata, n);
		}
		break;

	    case 5: //delete element
		printf("Enter the element you need to delete : ");
		scanf("%d", &ndata);

		if ((ret = sl_delete_element(&head, ndata)) == DATA_NOT_FOUND)
		{
		    printf("INFO : Element is not found\n");
		}
		else if (ret == LIST_EMPTY)
		{
		    printf("INFO : List is empty\n");
		}
		else
		{
		    printf("Element Successfully deleted\n");
		}
		break;

	    case 6: // print list
		//print list function call
		print_list(head);
		break;

	    case 7:
		return SUCCESS;

	    default: printf("Enter proper choice !!\n");
		     break;
	}
    }

    return SUCCESS;
}
