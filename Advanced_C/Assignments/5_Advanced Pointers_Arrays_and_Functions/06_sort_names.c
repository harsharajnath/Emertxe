/*


Name: Harsharaj Nath
Date of Submission: 31-07-22
Description: Read n & n person names of maxlen 32. Sort and print the names


Sample execution: -

Test Case 1:

Enter the size: 5

Enter the 5 names of length max 32 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:
Agra
Bengaluru
Chennai
Delhi
Kolkata


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include<stdlib.h>

void sort_names(char (*)[32], int);                                             //function prototype of sort_names() function
int my_strcmp(char *, char *);                                                  //function prototype of my_strcmp() function
void my_strcpy(char *, char *);                                                 //function prototype of my_strcpy() function

int main()
{
    int n;
    char (*aptr)[32];                                                           //declaring pointer to an array (FDSS)

    printf("Enter the size: ");
    scanf("%d", &n);                                                            //reading row size from user

    aptr = malloc(sizeof(*aptr) * n);                                           //dynamically allocating memory

    printf("\nEnter the %d names of length max 32 characters in each\n", n);
    for (int i = 0; i < n; i++)
    {
	printf("[%d] -> ", i);
	scanf(" %s", aptr[i]);                                                  //reading the names from user
    }

    sort_names(aptr, n);                                                        //function call for sorting

    printf("\nThe sorted names are:\n");

    for (int i = 0; i < n; i++)                                                 //printing the sorted names
    {
	printf("%s\n", aptr[i]);
    }

    free(aptr);                                                                 //freeing dynamically allocated memory
    aptr = NULL;

    return 0;
}

void sort_names(char (*aptr)[32], int n)                                        //function definition for sort_names()
{
    int ret;
    for(int i = 0; i < n; i++)
    {
	for(int j = 1; j < n; j++)
	{
	    ret = my_strcmp(aptr[j-1], aptr[j]);                                //comparing the strings

	    if (ret > 0)                                                        //if return value is +ve then swap the two strings
	    {
		char temp[32];

		my_strcpy(temp, aptr[j-1]);

		my_strcpy(aptr[j-1], aptr[j]);

		my_strcpy(aptr[j], temp);
	    }
	}
    }    
}


int my_strcmp(char *str1, char *str2)                                           //function definition for my_strcmp()
{
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')                     //
    {                                                                           //
	str1++;                                                                 //
	str2++;                                                                 //
    }                                                                           //  logic
										//
    if (*str1 == *str2)                                                         //
	return 0;                                                               //
    else                                                                        //
	return *str1 - *str2;                                                   //
}

void my_strcpy(char *dest, char *src)                                           //function definition for my_strcpy()
{
    while(*src)                                                                 //
    {                                                                           //
	*dest = *src;                                                           //
	src++;                                                                  //  logic
	dest++;                                                                 //
    }                                                                           //
    *dest = *src;                                                               //
}
