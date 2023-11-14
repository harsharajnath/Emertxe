/*


Name: Harsharaj Nath
Date of Submission: 02-07-22
Description: WAP to replace each string of one or more blanks by a single blank


Sample execution: -

Test Case 1:

Enter the string with more spaces in between two words
Pointers     are               sharp     knives.
Pointers are sharp knives.

Test Case 2:

Enter the string with more spaces in between two words
Welcome                to Emertxe
Welcome to Emertxe

Test Case 3:

Enter the string with more spaces in between two words
Welcome to Emertxe
Welcome to Emertxe


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void replace_blank(char *);                                                     //function prototype

int main()
{
    char str[100];                                                              //declaration

    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);                                                       //taking the string from user

    replace_blank(str);                                                         //function call

    printf("%s\n", str);                                                        //printing the multiple white space removed string
}

void replace_blank( char *str)                                                  //function definition
{
    int i = 0;                                                                  //initialization
    int j = 0;
    int k;
    int m;

    while(str[i] != '\0')                                                       //replacing all tabs (if any) with spaces for convinience
    {
	if( str[i] == '\t')
	{
	    str[i] = ' ';
	}
	i++;
    }

    while(str[0] == ' ')                                                        //if string starts with space(s), removing them all
    {
	for ( m = 0 ; str[m] != '\0'; m++ )
	{
	    str[m] = str[m+1];
	}
    }

    while(str[j] != '\0')                                                       //replacing multiples spaces with single space
    {
	int flag = 0;
	if(str[j] == ' ')
	{
	    if ( str[j] == str[j+1] )
	    {
		flag = 1;                                                       //flag is set when consecutive spaces are found
		for ( k = j; str[k] != '\0'; k++ )
		{
		    str[k] = str[k+1];
		}

	    }
	}
	if( flag == 0)
	{
	    j++;
	}
    }
}
