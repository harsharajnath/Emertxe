/*


Name: Harsharaj Nath
Date of Submission: 05-07-22
Description: WAP to implement getword function


Sample execution: -

Test Case 1:

Enter the string : Welcome to Emertxe
You entered Welcome and the length is 7

Test Case 2:

Enter the string : Hello
You entered Hello and the length is 5


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int getword(char *str);                                                         //function prototype

int main()
{
    int len = 0;                                                                //initialization
    char str[100];

    printf("Enter the string : ");
    scanf(" %[^\n]", str);                                                      //taking the input from user

    len = getword(str);                                                         //function calli

    printf("You entered %s and the length is %d\n", str, len);
}

int getword(char str[100])                                                      //function definition
{
    int i, j = 0;                                                               //initialization
    int count = 0;

    while(str[0] == ' ' || str[0] == '\t')                                      //if string starts with space(s) or tab(s), removing them all
    {
	for ( i = 0; str[i] != '\0'; i++ )
	{
	    str[i] = str[i+1];
	}
    }

    for ( j = 0; str[j] != '\0'; j++)                                           //loop to count the length of first word
    {
	if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')                  //condition if space, tab or new line is detected
	{
	    str[j] = '\0';                                                      //replacing the jth position with NULL character so that %s prints only the first word
	    break;
	}
	else
	    count++;                                                            //counting the characters
    }

    return count;                                                               //returning the count

}

