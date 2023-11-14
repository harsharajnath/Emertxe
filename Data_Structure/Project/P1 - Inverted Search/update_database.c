#include "inverted_search.h"

extern Flist *f_head_init;

void update_database(Wlist *head[] , Flist **f_head)
{
    //variable declaration
    int empty;
    char file_name[FNAME_SIZE];

    //prompt the user to enter
    printf("Enter the filename: ");
    scanf("%s", file_name);

    //validate the file_name
    empty = isFileEmpty(file_name);

    if(empty == FILE_NOTAVAILABLE)
    {
	printf("\033[0;31m");
	printf("File : %s is not available\n" , file_name);
	printf("Hence we are not adding into the file list\n");
	printf("\033[0m");
    }
    else if(empty == FILE_EMPTY)
    {
	printf("\033[0;31m");
	printf("File : %s is not having any contents in it\n" , file_name);
	printf("Hence we are not adding into the file list\n");
	printf("\033[0m");
    }
    else
    {
	//restore initial file head
	*f_head = f_head_init;

	int ret_val = to_create_list_of_files(f_head , file_name);

	if(ret_val == SUCCESS)
	{
	    printf("\033[0;32m");
	    printf("Successful : Inserting the file name : %s into the file linked list\n" , file_name);

	    //traverse till the till last node
	    while((*f_head) -> link != NULL)
	    {
		*f_head = (*f_head)->link;
	    }

	    //create database
	    create_database(*f_head,head);

	    printf("Successful : Updated database with file : %s\n", file_name);
	    printf("\033[0m");
	}
	else if (ret_val == REPEATATION)
	{
	    printf("\033[0;33m");
	    printf("This file name : %s is repeated, Hence we are not adding to the list\n" , file_name);
	    printf("\033[0m");
	}
	else
	{
	    printf("\033[0;31m");
	    printf("FAILURE\n");
	    printf("\033[0m");
	}
    }
}
