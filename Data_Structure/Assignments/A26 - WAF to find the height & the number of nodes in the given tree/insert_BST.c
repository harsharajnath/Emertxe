#include "tree.h"

/* Function to insert the data's in BST */
int insert_into_BST(Tree_t **root, int data)
{
    //variable declaration
    int flag;

    //creating a new tree node
    Tree_t *new = malloc(sizeof(Tree_t));

    //checking if memory is alloted
    if(new == NULL)
    {
	return FAILURE;
    }

    //updating new tree node data and links
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;

    //checking if tree is empty
    if(*root == NULL)
    {
	//updating root with new node
	*root = new;
	return SUCCESS;
    }

    //taking local reference pointers
    Tree_t *temp = *root;   //to traverse the tree nodes
    Tree_t *parent;     //to store the parent node address 

    while(temp != NULL)
    {
	//updating the parent pointer
	parent = temp;

	//if given data is less than the temp node data
	if(data < (temp -> data))
	{
	    //updating temp with the left child address
	    temp = temp -> left;

	    //flag value 1 indicates left
	    flag = 1;
	}
	//f given data is greater than the temp node data
	else if(data > (temp -> data))
	{
	    //updating temp with the right child address
	    temp = temp -> right;

	    //flag value 0 indicates right
	    flag = 0;
	}
	//when duplicate data is given
	else
	{
	    return DUPLICATE;
	}
    }

    //inserting the new node in correct position
    if(flag == 1)
    {
	parent -> left = new;
    }
    else
    {
	parent -> right = new;
    }

    return SUCCESS;
}
