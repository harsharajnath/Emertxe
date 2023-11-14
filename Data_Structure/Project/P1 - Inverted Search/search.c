#include "inverted_search.h"

int search(Wlist *head , char *word)
{
    //check list is empty or not 
    if(head == NULL)
    {
	printf("\033[0;31m");
	printf("List is empty, search word is not found\n");
	printf("\033[0m");
	return 1;
    }

    //traverse through the Wlist 
    while(head)
    {
	//compare the node word with search word
	if(!(strcmp(head->word , word)))
	{
	    printf("\033[0;32m");
	    printf("Word %s is present in %d file(s)\n" , word , head->file_count);
	    printf("\033[0m");

	    //create local reference pointer
	    Ltable *Thead = head->Tlink;
	    
	    //traverse through the Ltable till last node
	    while(Thead)
	    {
		printf("\033[0;36m");
		printf("In file : %s   %d  time(s)\n" , Thead->file_name , Thead->word_count);
		printf("\033[0m");
		Thead = Thead->table_link;
	    }

	    printf("\n");
	    
	    return 0;
	}

	head = head->link;
    }

    printf("\033[0;31m");	
    printf("Search word not found in the given Wlist\n");
    printf("\033[0m");
    
    return 0;
}
