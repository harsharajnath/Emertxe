#include "tree.h"

/* Function to print the tree in pre order */
int preorder(Tree_t *root)
{
    //printing the data while preorder Traversing
    //if the root is not equal to NULL
    if(root != NULL)
    {
	//printing the data
	printf("%d ", root -> data);

	//calling the function recursively
	preorder(root -> left);

	//calling the function recursively
	preorder(root -> right);
    }
}
