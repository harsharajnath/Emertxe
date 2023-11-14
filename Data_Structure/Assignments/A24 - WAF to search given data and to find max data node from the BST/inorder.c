#include "tree.h"

/* Function to print the data in in order printing */
int inorder(Tree_t *root)
{
    //printing the data while inorder Traversing
    //if the root is not equal to NULL
    if(root != NULL)
    {
	//calling the function recursively
	inorder(root -> left);

	//printing the data
	printf("%d ", root -> data);

	//calling the function recursively
	inorder(root -> right);
    }
}
