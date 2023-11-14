#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through file LL
    while(f_head)
    {
	read_datafile(f_head, head, f_head -> file_name);
	f_head = f_head->link;
    }
}

Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //initialization
    int flag;
    fname = filename;

    //declaration
    char word[WORD_SIZE];

    //opening file in read mode
    FILE *fptr = fopen(filename , "r");

    //reading words from the file
    while(fscanf(fptr, "%s", word) != EOF)
    {
	//reset flag after each new word fetch
	flag = 1;

	//index
	int index = tolower(word[0]) % 97;

	// other than alphabets
	if( !(index >=0 && index <= 25))
	{
	    index = 26;
	}

	//if word word list is not empty
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];

	    //compare the word at each node with new word
	    while(temp)
	    {
		//if duplicate word found
		if(! strcmp(temp->word,word))
		{
		    update_word_count(&temp , filename);

		    //update flag	    
		    flag = 0;

		    break;
		}
		else
		{
		    temp = temp -> link;
		}
	    }

	    if(flag == 1)
	    {
		//words are not repeated
		insert_at_last(&head[index] , word);
	    }
	}

	//if word list is empty
	else if(head[index] == NULL)
	{
	    insert_at_last(&head[index] , word);
	}
    }
}


int update_word_count(Wlist **head , char *file_name)
{
    //creating local reference pointer
    Ltable *temp = (*head) -> Tlink;

    //checking if file names are same
    /* if names are equal, strcmp() returns 0
       takeing !strcmp() so that condition is
       true inside if condition */

    if(! strcmp(temp -> file_name,file_name))
    {
	//incrementing the word count
	temp -> word_count = (temp -> word_count) + 1;
    }

    //if file names are different
    else
    {
	// create node
	Ltable *new = malloc(sizeof(Ltable));

	// error check
	if(new == NULL)
	{
	    return FAILURE;
	}

	//updating the node parts
	new->word_count = 1;
	strcpy(new->file_name , fname);
	new->table_link = NULL;

	//traversing till the end of list
	while(temp -> table_link != NULL)
	{
	    temp = temp -> table_link;
	}

	//updating last node link with the address of new node
	temp->table_link = new;

	//incrementing the file count
	(*head) -> file_count = ((*head) -> file_count) + 1;
    }

    return SUCCESS;
}
