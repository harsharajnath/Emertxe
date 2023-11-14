#include "inverted_search.h"

void save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];

    //prompt the user to enter new file_name for saving the database
    printf("Enter the filename: ");
    scanf("%s" , file_name);

    //open the file in write mode
    FILE *fptr = fopen(file_name , "w");

    for(int i = 0 ; i < 27 ; i++)
    {
	if(head[i] != NULL)
	{
	    write_databasefile(head[i] , fptr);
	}
    }
}

void write_databasefile(Wlist *head , FILE *databasefile)
{
    //traverse through the Wlist till last node
    while(head != NULL)
    {
	int count = 0;

	fprintf(databasefile, "#[%d]\nWord is [%s]  :  file count is %d file(s)  :", tolower(head -> word[0])%97, head -> word, head -> file_count);

	//creating local reference pointer
	Ltable *Thead = head->Tlink;

	//traverse through the Ltable till last node
	while(Thead)
	{
	    if(count == 0)
	    {
		fprintf(databasefile, "  file is %s --- word count is %d", Thead->file_name, Thead -> word_count);
		count++;
	    }
	    else
	    {
		fprintf(databasefile, "  :  file is %s --- word count is %d", Thead->file_name, Thead-> word_count);
	    }


	    Thead = Thead->table_link;
	}
	
	fprintf(databasefile, "\n\n");
	
	head = head -> link;
    }
}
