#include "tree.h"

/* Function to print the data in in order printing */
int inorder(Tree_t *root)
{
    /* If the root is not equal to NULL */
    if (root != NULL)
    {
	/* Calling the function recursively  */
	inorder(root -> left);

	/* Printing the data */
	printf("%d ", root -> data);

	/* Calling the function recursively  */
	inorder(root -> right);
    }
    //return FAILURE;
}
