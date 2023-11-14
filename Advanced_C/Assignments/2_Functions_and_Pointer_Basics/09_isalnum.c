/*


Name: Harsharaj Nath
Date of Submission: 15-06-22
Description: WAP to implement your own isalnum() function


Sample execution: -

Test Case 1:

Enter the character: a
The character 'a' is an alnum character.

Test Case 2:

Enter the character: ?
The character '?' is not an alnum character.


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int my_isalnum(char);                                                           //function prototype

int main()
{
    char ch;                                                                    //initializtion
    int ret;

    printf("Enter the character: ");
    scanf("%c", &ch);                                                           //taking a character from user

    ret = my_isalnum(ch);                                                       //function call

    if ( ret == 1 )
    {
	printf("Entered character is alphanumeric character\n");
    }
    else
    {
	printf("Entered character is not alphanumeric character\n");
    }
}

int my_isalnum(char ch)                                                         //function definition
{
    if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))                  //condition to check for alphanumeric characters
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
