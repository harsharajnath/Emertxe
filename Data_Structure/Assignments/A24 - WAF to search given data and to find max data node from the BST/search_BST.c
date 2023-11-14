#include "tree.h"

/* Function to search for data in BST iteratively */
int search_BST(Tree_t *root, int data)
{
    //checking if tree is empty
    if(root == NULL)
    {
	return FAILURE;
    }

    //taking local reference pointer to traverse the tree nodes
    Tree_t *temp = root;

    while( temp != NULL)
    {
	//if give data is less than the temp node data
	if(data < (temp -> data))
	{
	    //updating temp with the left child address
	    temp = temp -> left;
	}
	//if give data is greater than the temp node data
	else if (data > (temp -> data))
	{
	    //updating temp with the right child address
	    temp = temp -> right;
	}
	//when give data is neither greater than or less than the temp node data
	//this implies, the data is found
	else
	{
	    return SUCCESS;
	}
    }

    //if data did not matched
    return NOELEMENT;
}
