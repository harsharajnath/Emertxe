#include "tree.h"

/* Function to print the tree in post order */
int postorder(Tree_t *root)
{
    //printing the data while postorder Traversing
    //if the root is not equal to NULL
    if(root != NULL)
    {
	//calling the function recursively
	postorder(root -> left);

	//calling the function recursively
	postorder(root -> right);

	//printing the data
	printf("%d ", root -> data);
    }
}
