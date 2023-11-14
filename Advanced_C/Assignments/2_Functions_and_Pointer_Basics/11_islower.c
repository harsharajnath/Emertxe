/*


Name: Harsharaj Nath
Date of Submission: 15-06-22
Description: WAP to implement your own islower() function


Sample execution: -

Test Case 1:

Enter the character: a
Entered character is lower case alphabet

Test Case 2:

Enter the character:3
Entered character is not lower case alphabet


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int my_islower(char);                                                           //function prototype

int main()
{
    char ch;                                                                    //initializtion
    int ret;

    printf("Enter the character: ");
    scanf("%c", &ch);                                                           //taking a character from user

    ret = my_islower(ch);                                                       //function call

    if ( ret == 1 )
    {
	printf("Entered character is lower case alphabet\n");
    }
    else
    {
	printf("Entered character is not lower case alphabet\n");
    }
}

int my_islower(char ch)                                                         //function definition
{
    if ( ch >= 97 && ch <= 122 )                                                //condition to check for lower case characters
    {
	return 1;
    }
    else
    {
	return 0;
    }
}
