#include "tree.h"

int find_height(Tree_t *root)
{
    // variable declaration
    int count_left;
    int count_right;

    //when leaf node is reached
    if (root == NULL)
    {
	return 0;
    }

    // calling the funtion recursively towards left child
    count_left = find_height(root -> left);

    //calling the function recursively towards right child
    count_right = find_height(root -> right);

    // choosing the larger count
    if (count_left > count_right)
    {
	return count_left + 1;
    }
    else
    {
	return count_right + 1;
    }
}
