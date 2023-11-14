/*


Name: Harsharaj Nath
Date of Submission: 02-07-22
Description: WAP to count no. of characters, words and lines, entered through stdin


Sample execution: -

Test Case 1:

Hello world
Dennis Ritchie
Linux
Character count : 33
Line count : 3
Word count : 5

Test Case 2:

Hello         world
Dennis    Ritchie
Linux
Character count : 39
Line count : 3
Word count : 5


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <ctype.h>

int main()
{
    int char_count = 0;                                                         /*initializtion*/
    int line_count = 0;
    int word_count = 0;
    char ch, prev_ch;

    while(( ch = getchar()) != EOF )                                            /*main loop*/
    {
	char_count++;                                                           /*incrementing the character count*/

	if ( ch == '\n' )                                                       /*condition for line count*/
	{
	    line_count++;                                                       /*incrementing the line count*/
	}

	if ( ch == ' ' || ch == '\t' || ch == '\n' )                            /*condition for word count*/
	{
	    if ( char_count > 1 )                                               /*if character count is more than 1*/
	    {
		if (    (prev_ch == ch) ||                                      /*if continuous space or tab*/

			(prev_ch == ' ' && ch == '\t') ||                       /*if space followed by tab*/
			(prev_ch == '\t' && ch == ' ') ||                       /*if tab followed by space*/

			(prev_ch == ' ' && ch == '\n') ||                       /*if space followed by new line*/
			(prev_ch == '\n' && ch == ' ') ||                       /*if new line followed by space*/

			(prev_ch == '\n' && ch == '\t') ||                      /*if new line followed by tab*/
			(prev_ch == '\t' && ch == '\n')     )                   /*if tab followed by new line*/
		{	}                                                       /*do nothing*/
		else
		    word_count++;                                               /*incrementing the word count*/
	    }
	}
	else
	{
	    if (char_count == 1 )                                               /*if one or more character enterd without space, tab or new line at the end it will be considered as a word*/
		word_count++;                                                   /*incrementing the word count*/
	}

	prev_ch = ch;                                                           /*updating the previous character variable*/
    }

    if (ch == EOF)                                                              /*if EOF is reached*/
    {
	if( prev_ch == ' ' || prev_ch == '\t' || prev_ch == '\n')               /*condition to check if last character is space, tab or new line*/
	{                                                                       /*if yes, then checking the word count*/
	    if( word_count != 0 )                                               /*if word count is not equal to 0 then decrementing the count by 1*/
		word_count--;                                                   /*we are adjusting the word count because if last character is space, tab or new line*/
	}                                                                       /*(contd.) it will increment the word count according to the above mention condition */
    }

    printf("\nCharacter count : %d\n", char_count);                             /*printing the character count*/
    printf("Line count : %d\n", line_count);                                    /*printing the line count*/
    printf("Word count : %d\n", word_count);                                    /*printing the word count*/

    return 0;
}
