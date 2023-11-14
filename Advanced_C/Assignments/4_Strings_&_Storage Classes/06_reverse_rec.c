/*


Name: Harsharaj Nath
Date of Submission: 09-07-22
Description: WAP to reverse the given string using recursive method


Sample execution: -

Test Case 1:

Enter a string : Hello World
Reverse string is : dlroW olleH

Test Case 2:

Enter a string : EMERTXE
Reverse string is : EXTREME


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void reverse_recursive(char *str, int index, int len);                          //function prototype

int main()
{
    char str[30];
    int strlen = 0;
    int index = 0;
    int i = 0;
    int len;


    printf("Enter any string : ");
    scanf("%[^\n]", str);                                                       //taking string from the user

    while (str[i] != '\0')                                                      //finding the string length
    {
	strlen++;
	i++;
    }

    len = strlen - 1;

    reverse_recursive(str, index, len);                                         //function call

    printf("Reversed string is %s\n", str);                                     //printing the revesed string
}

void reverse_recursive(char *str, int index, int len)                           //function definition
{

    char swap;

    swap = str[index];                                                      //logic to reverse the string
    str[index] = str[len];
    str[len] = swap;

    index++;
    len--;

    if( index < len )
    {
	reverse_recursive(str, index, len);                                 //recursive function call
    }
}

