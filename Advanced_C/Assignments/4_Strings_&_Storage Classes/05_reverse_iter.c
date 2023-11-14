/*


Name: Harsharaj Nath
Date of Submission: 09-07-22
Description: WAP to reverse the given string using iterative method


Sample execution: -

Test Case 1:

Enter a string : Hello World
Reverse string is : dlroW olleH

Test Case 2:

Enter a string : EMERTXE
Reverse string is : EXTREME


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void reverse_iterative(char *str);                                              //function prototype 

int main()
{
    char str[30];

    //printf("Enter any string : ");
    scanf("%[^\n]", str);                                                       //taking string from user

    reverse_iterative(str);                                                     //function call

    printf(" Reversed string is %s\n", str);                                    //printing the reversed string
}

void reverse_iterative(char *str)                                               //function definition
{
    int i = 0;
    int strlen = 0;
    int index = 0;
    int len;
    int limit;
    char swap;

    while ( str[i] != '\0')                                                     //finding the string length
    {
	strlen++;
	i++;
    }

    len = strlen - 1;
    limit = len / 2;
    for ( int j = 0; j <= limit; j++ )                                          //reversing the string
    {
	swap = str[index];
	str[index] = str[len];
	str[len] = swap;

	index++;
	len--;
    }
}
