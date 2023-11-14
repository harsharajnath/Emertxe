/*


Name: Harsharaj Nath
Date of Submission: 24-11-22
Description: WAF to delete the given data node from the BST


Sample execution: -

Cases:
Node to be deleted may be,
1. Leaf node
2. Node with single child
3. Node with two children


#########################################_Program_begins_from_here_######################################### */


#include "tree.h"

int status;

int main()
{
    /* Intializing the root with NULL */
    Tree_t *root = NULL;
    int result;
    /* Declaring the variables */
    int option, data;

    //printf("1. insert BST\n2. in order Traversal\n3.BST Delete\n4.Exit\n");
    //printf("Enter the option: ");
    while (1)
    {
	scanf("%d", &option);

	switch(option)
	{
	    case 1:
		/* Reading the data from the user */
		printf("Enter the data to insert into the BST : ");
		scanf("%d", &data);

		/* Calling the function to insert the element */
		if ((result = insert_into_BST(&root, data)) == DUPLICATE)
		{
		    printf("INFO : Duplicate found\n");
		}
		else if (result == FAILURE)
		{
		    printf("INFO : Node not created\n");
		}
		break;
	    case 2:
		/* Function to Printing the data in in-order form */
		inorder(root);
		printf("\n");
		break;

	    case 3:
		/* Function to delete the data from the tree */
		printf("Enter the data to be deleted: ");
		scanf("%d", &data);
		if (root)
		{
		    root = delete_BST(root, data);
		    if (status)
			printf("INFO : Element deleted successfully\n");
		    else
			printf("INFO : Element not found\n");
		}
		else
		    printf("INFO : Tree is empty\n");

		break;
	    case 4:

		return SUCCESS;
		break;

	    default:
		printf("Invalid Option\n");
	}

	/* If user press y means loop will continue */
    }
    return 0;
}
