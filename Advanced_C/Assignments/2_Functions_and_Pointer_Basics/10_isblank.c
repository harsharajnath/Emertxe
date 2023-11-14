/*


Name: Harsharaj Nath
Date of Submission: 15-06-22
Description: WAP to implement your own isblank() function


Sample execution: -

Test Case 1:

Enter the character: a
The character 'a' is not a blank character.

Test Case 2:

Enter the character:    //Entered space
The character ' ' is a blank character.


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int my_isblank(char);                                                           //function prototype

int main()
{
    char ch;                                                                    //initializtion
    int ret;

    printf("Enter the character: ");
    scanf("%c", &ch);                                                           //taking a character from user

    ret = my_isblank(ch);                                                       //function call

    if ( ret == 1 )
    {
	printf("Entered character is a blank character\n");
    }
    else
    {
	printf("Entered character is not blank character\n");
    }
}

int my_isblank(char ch)                                                         //function definition
{
    if (ch == 9 || ch == 32 )                                                   //condition to check for blank characters
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
