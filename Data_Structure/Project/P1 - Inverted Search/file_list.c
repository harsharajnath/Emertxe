#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    //initialization
    int i = 1;

    //varialbe declaration
    int empty; 

    //traverse through all argument vectors, i.e the file names
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);

	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("\033[0;31m");
	    printf("File : %s is not available\n" , argv[i]);
	    printf("Hence we are not adding into the file list\n");
	    printf("\033[0m");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("\033[0;31m");
	    printf("File : %s is not having any contents in it\n" , argv[i]);
	    printf("Hence we are not adding into the file list\n");
	    printf("\033[0m");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS)
	    {
	        printf("\033[0;32m");
		printf("Successful : Inserting the file name : %s into the file linked list\n" , argv[i]);
	        printf("\033[0m");
		i++;
	    }
	    else if (ret_val == REPEATATION)
	    {
	        printf("\033[0;33m");
		printf("This file name : %s is repeated, Hence we are not adding to the list\n" , argv[i]);
	        printf("\033[0m");
		i++;
	    }
	    else
	    {
	        printf("\033[0;31m");
		printf("FAILURE\n");
	        printf("\033[0m");
		break;
	    }
	}
    }
}

//function to check for file availability and for its contents.
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");

    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    fseek(fptr , 0 , SEEK_END);

    if(ftell(fptr) == 0)
    {
	return FILE_EMPTY;
    }
}


int to_create_list_of_files(Flist **f_head, char *name)
{
    //crete node
    Flist *new = malloc(sizeof(Flist));

    //error check for memory allocation
    if(new == NULL)
    {
	return FAILURE;
    }

    //updating the node parts
    strcpy(new -> file_name, name);
    new -> link = NULL;

    //check for list empty or not
    if(*f_head == NULL)
    {
	*f_head = new;
	return SUCCESS;
    }

    //create local reference pointer
    Flist *temp = *f_head;
    Flist *temp_prev;

    if(temp -> link == NULL)
    {
	//checking if duplicate file name present
	if(strcmp(temp -> file_name, name) == 0)
	{
	    return REPEATATION;
	}
    }

    //traversing through the list till last node
    while(temp != NULL)
    {
	//checking if duplicate file name present
	if(strcmp(temp -> file_name, name) == 0)
	{
	    return REPEATATION;
	}

	temp_prev = temp;
	temp = temp -> link;
    }

    //when last node is reached, establishing the link between the last node and the new node
    temp_prev -> link = new;

    return SUCCESS;
}
