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
    Tree_t *temp = root -> left;

    //taking local reference pointer which is parent node of the min value node
    Tree_t *pos = root;

    while(temp != NULL)
    {
	if((temp -> data) < min)
	{
	    //updating the min value
	    min = temp -> data;

	    if(temp -> left != NULL)
	    {
		//updating the pos pointer
		pos = temp;
	    }

	    //updating the temp
	    temp = temp -> left;
	}
    }

    //storing NULL in place of min value node
    pos -> left = NULL;

    //returning the min value
    return min;
}
