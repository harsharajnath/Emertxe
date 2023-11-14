#include "tree.h"

extern int status;
/* Function to delete the node  */
Tree_t * delete_BST(Tree_t * root, int data)
{
    //variable declaration
    int flag;

    //taking local reference pointers
    Tree_t *temp = root;   //to traverse the tree nodes
    Tree_t *parent;     //to store the parent node address 

    while(temp != NULL)
    {
	//if given data is less than the temp node data
	if(data < (temp -> data))
	{
	    //updating the parent pointer
	    parent = temp;

	    //updating temp with the left child address
	    temp = temp -> left;

	    //flag value 1 indicates left
	    flag = 1;
	}

	//f given data is greater than the temp node data
	else if(data > (temp -> data))
	{
	    //updating the parent pointer
	    parent = temp;

	    //updating temp with the right child address
	    temp = temp -> right;

	    //flag value 0 indicates right
	    flag = 0;
	}

	//when give data is neither greater than or less than the temp node data
	//this implies, the data is found
	else
	{
	    //if tree node is leaf node
	    if((temp -> left) == NULL && (temp -> right) == NULL)
	    {
		//for left node
		if(flag == 1)
		{
		    //updating the parent link
		    parent -> left = NULL;
		}
		//for right node
		else
		{
		    //updating the parent link
		    parent -> right = NULL;
		}

		//deallocating the meomory
		free(temp);

		status = 1;
	    }
	    //if node has only right child
	    else if ((temp -> left) == NULL && (temp -> right) != NULL)
	    {
		//updating the parent link
		parent -> right = temp -> right;

		//deallocating the meomory
		free(temp);

		status = 1; 
	    }
	    //if node has only left child
	    else if ((temp -> left) != NULL && (temp -> right) == NULL)
	    {
		//updating the parent link
		parent -> left = temp -> left;

		//deallocating the meomory
		free(temp);

		status = 1; 
	    }
	    //if node has two children
	    else if ((temp -> left) != NULL && (temp -> right) != NULL)
	    {
		//updating temp data with the lowest value from right sub tree 
		temp -> data = findmin(temp -> right);

		status = 1;
	    }
	}
    }

    return root;
}
