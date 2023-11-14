/*


Name: Harsharaj Nath
Date of Submission: 15-06-22
Description: WAP to implement your own ispunct() function


Sample execution: -

Test Case 1:

Enter the character: a
Entered character is not punctuation character

Test Case 2:

Enter the character:$
Entered character is punctuation character


#########################################_Program_begins_from_here_######################################### */

#include <stdio.h>

int my_ispunct(char);                                                           //function prototype

int main()
{
    char ch;                                                                    //initializtion
    int ret;

    printf("Enter the character: ");
    scanf("%c", &ch);                                                           //taking a character from user

    ret = my_ispunct(ch);                                                       //function call

    if ( ret == 1 )
    {
	printf("Entered character is punctuation character\n");
    }
    else
    {
	printf("Entered character is not punctuation character\n");
    }
}

int my_ispunct(char ch)                                                         //function definition
{
    if ( (ch >= 0 && ch <= 31) || ch == 127 || (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 9 || ch == 32 )              //condition to check for punctuation characters
    {
	return 0;
    }
    else
    {
	return 1;
    }
}
