/*


Name: Harsharaj Nath
Date of Submission: 25-11-22
Description: WAF to find the height & the number of nodes in the given tree.


Sample execution: -

Cases:	
1. Tree Empty

2. Tree Non-Empty
INFO : Total no.of nodes are 8
INFO : Height of the tree is 4


#########################################_Program_begins_from_here_######################################### */


#include "tree.h"

int status;

int main()
{
    /* Intializing the root with NULL */
    Tree_t *root = NULL;

    /* Declaring the variables */
    int option, data, result;

    //printf("1. insert BST\n2. in order Traversal\n3. Find height\n4. 4.Exit\n");
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
		/* Function to find total no. of nodes in the tree */

		if ((result = total_nodes(root)) == 0)
		{
		    printf("INFO : Tree is empty\n");
		}
		else
		{
		    printf("INFO : Total no.of nodes are %d\n", result);
		}       
		break;

	    case 4:
		/* Function to find the height of the tree */
		if ((result = find_height(root)) == 0)
		{
		    printf("INFO : Tree is empty\n");
		}
		else
		{
		    printf("INFO : Height of the tree is %d\n", result);
		}
		break;

	    case 5:
		/* exit */
		return SUCCESS;
		break;

	    default:
		printf("Invalid Option\n");
	}

	/* If user press y means loop will continue */
    }
    return 0;
}
