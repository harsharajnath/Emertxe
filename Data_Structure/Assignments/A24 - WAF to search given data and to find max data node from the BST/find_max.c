#include "tree.h"

/* Functon to find the maximum value in BST */
int findmax(Tree_t *root)
{
    //variable declaration
    int max;

    //checking if tree is empty
    if(root == NULL)
    {
	return FAILURE;
    }

    //initializing max with root data
    max = root -> data;

    //taking local reference pointer to traverse the tree nodes
    /* temp pointer is pointing to right child initially, because max value
       will be towards right side of the BST */
    Tree_t *temp = root -> right;

    while(temp != NULL)
    {
	if((temp -> data) > max)
	{
	    //updating the max value
	    max = temp -> data;

	    //updating the temp
	    temp = temp -> right;
	}
    }

    //returning the max value
    return max;
}
