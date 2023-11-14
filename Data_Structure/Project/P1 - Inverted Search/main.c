/*


Name: Harsharaj Nath

Date of Submission: 01-12-22

Project Name: Inverted Search

Project Description: The purpose of storing an index is to optimize speed and performance in finding relevant documents
for a search query. Without an index, the search engine would scan every document in the corpus, which would require
considerable time and computing power.

An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its
locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow
fast full text searches, at the cost of increased processing when a document is added to the database. The inverted
file may be the database file itself, rather than its index. It is the most popular data structure used in document
retrieval systems, used on a large scale for example in search engines


#########################################_Program_begins_from_here_######################################### */


#include "inverted_search.h"

Flist *f_head_init = NULL; 

int main(int argc, char *argv[])
{
    system("clear");

    //variable declaration
    char option;
    int choice;

    Wlist *head[27] = {NULL};

    //Validate CLA
    if(argc <= 1)
    {
        printf("\033[0;31m");
	printf("Enter the valid no. arguments \n");
	printf("./SList.exe file1.txt file2.txt ......\n");
	printf("\033[0m");
	return 0;
    }

    //create file list
    //declare the file head
    Flist *f_head = NULL;

    //validate the files
    file_validation_n_file_list(&f_head, argv);

    //backup initial file head
    f_head_init = f_head;

    //verifying the file list
    if(f_head == NULL)
    {
	printf("\033[0;31m");
	printf("No files are available in the file LL\n");
	printf("Hence the process terminated\n");
	printf("\033[0m");	
	return 1;
    }

    // prompt the user for choice
    do
    {
	printf("\nSelect your choice among following options:\n");
	printf("1. Create DATABASE\n");
	printf("2. Display Database\n");
	printf("3. Update DATABASE\n");
	printf("4. Search\n");
	printf("5. Save Database\n");

	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	printf("\n");

	switch(choice)
	{
	    case 1:

		//Create Database 
		create_database(f_head , head);
		{
		    while(f_head != NULL)
		    {
			printf("\033[0;32m");
			printf("Successful: Creation of database for file : %s\n", f_head -> file_name);
			printf("\033[0m");			
			f_head = f_head -> link;
		    }
		}
		break;

	    case 2:

		//Display Database
		display_database(head);
		break;

	    case 3:

		//Update Database
		update_database(head,&f_head);
		break;

	    case 4:
		
		//Search in Databae
		{
		    char word[WORD_SIZE];

		    //promt the user to enter the search word
		    printf("Enter the word to search: ");
		    scanf("%s", word);
		    
		    search(head[tolower(word[0])%97] , word);
		}
		break;

	    case 5:

		//Save Database
		save_database(head);
		break;

	    default:

		printf("Invalid option\n");
	}

	/* check for continue */
	printf("\nDo you want to continue (y/n): ");
	scanf("\n%c", &option);

    } while (option == 'y' || option == 'Y');

    return 0;
}
