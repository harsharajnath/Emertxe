#include "tree.h"

/* Functon to find the minimum value in BST */
int findmin(Tree_t *root)
{
    //variable declaration
    int min;

    //checking if tree is empty
    if(root == NULL)
    {
	return FAILURE;
    }

    //initializing min with root data
    min = root -> data;

    //taking local reference pointer to traverse the tree nodes
    /* temp pointer is pointing to left child initially, because min value
       will be towards left side of the BST */
    Tree_t *temp = root -> left;

    while(temp != NULL)
    {
	if((temp -> data) < min)
	{
	    //updating the min value
	    min = temp -> data;

	    //updating the temp
	    temp = temp -> left;
	}
    }

    //returning the min value
    return min;
}
