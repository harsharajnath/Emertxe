#include "tree.h"

/* Function to find total no. of nodes in the tree */
int total_nodes(Tree_t *root)
{
    static int count_node;

    // if the root is not equal to NULL
    if (root != NULL)
    {
	// calling the function recursively
	total_nodes(root -> left);

	// incrementing the count
	count_node++;

	// calling the function recursively
	total_nodes(root -> right);
    }

    return count_node;
}
