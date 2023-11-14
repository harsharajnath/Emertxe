#include "inverted_search.h"

void display_database(Wlist *head[])
{
    //print the column names
    printf("\033[0;33m");
    printf("[INDEX]\t\t\t[WORD]\t\t\tFILE_COUNT FILE(S)\t\t\tFILE: FILE_NAME\t\t\tWORD_COUNT\n");
    printf("\n");
    printf("\033[0m");

    for(int i=0; i<27; i++)
    {
	if(head[i] != NULL)
	{
	    print_word_count(head[i]);
	}
    }
}

int print_word_count(Wlist *head)
{
    //traverse through the Wlist till last node 
    while(head != NULL)
    {
	int count = 0;
	printf("[%d]\t\t\t[%s]\t\t\t\t%d  file(s)" , tolower(head->word[0])%97 , head->word , head->file_count);

	//creating local reference pointer
	Ltable *Thead = head->Tlink;

	//travere through the Ltable till last node
	while(Thead)
	{
	    if(count == 0)
	    {
		printf("\t\t\tFile: %s\t\t\t\t%d\n", Thead->file_name , Thead->word_count);
		count++;
	    }
	    else
	    {
		printf("\t\t\t\t\t\t\t\t\t\t\tFile: %s\t\t\t\t%d\n", Thead->file_name , Thead->word_count);
	    }

	    Thead = Thead->table_link;
	}

	printf("\n");

	head = head -> link;
    }
}
