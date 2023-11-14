/*


Name: Harsharaj Nath
Date of Submission: 10-07-22
Description: WAP to implement strtok function


Sample execution: -

Test Case 1:

Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai

Test Case 2:

Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

int match_found = 0;                                                            //global variable

char *my_strtok(char *str, const char *delim);                                  //function prototype

int main()
{
    static char str[50];
    char delim[50];

    printf("Enter the string  : ");
    scanf("%s", str);                                                           //taking the string from user
    __fpurge(stdout);

    printf("Enter the delimeter : ");
    scanf("\n%s", delim);                                                       //taking the delimiter array from user
    __fpurge(stdout);

    char *token = my_strtok(str, delim);                                        //function call

    printf("Tokens :\n");

    while (token != NULL)
    {
	if( *token == '\0' )                                                    //if token value is '\0', do nothing
	{
	    ;
	}
	else
	{
	    printf("%s\n", token);                                              //printing the token
	}

	if ( match_found == 1)
	{
	    token = my_strtok( NULL, delim);                                    //recursive funtion call with NULL as input
	}
	else if ( match_found == 0)
	{
	    break;
	}
    }
}

char *my_strtok(char *str, const char *delim)                                   //function definition
{

    static int index = 0;                                                       //initialization
    static int pos = 0;
    static int count = 0;
    static char *next_element;


    if (str != NULL)                                                            //for the 1st function call
    {
	index = pos;
	index = 0;

	while(str[index] != '\0')                                               //loop to compare each element
	{
	    int flag1 = 0;                                                      
	    for(int j = 0; delim[j] != '\0'; j++)                               //loop to compare each element of string with delimiter
	    {
		if(str[index] == delim[j])                                      //if match found
		{
		    str[index] = '\0';                                          //replacing the element with '\0'
		    flag1 = 1;
		    match_found = 1;                                            //this flag is set when atleast one match is found

		    if (flag1 == 1)                                             //condition to check if next consecutive string element match with delimiter
		    {
			int flag2 = 0;

			while (flag2 != 1)                                      //2nd while loop to check if next consecutive string element match with delimiter
			{
			    index++;
			    int flag3 = 0;

			    for(int k = 0; delim[k] != '\0'; k++)
			    {
				if(str[index] == delim[k])
				{
				    str[index] = '\0';
				    flag3 = 1;
				    break;
				}
			    }

			    if (flag3 == 1)                                     //conditon to stop the 2nd while loop
			    {
				flag2 = 0;
			    }
			    else if ( flag3 == 0)
			    {
				flag2 = 1;
			    }
			}

			next_element = &str[index];                             //storing current element address in pointer
			pos = index;                                            //storing current index position in pos
			index = 0;                                              //updating index with 0
			return &str[index];                                     //returning the base address of token
		    }
		}
	    }

	    pos = 0;  
	    index++;

	}

	if( str[index] == '\0')                                                 //when the '\0' is reached
	{
	    if (count == 0)
	    {
		count++;
		return &str[pos];
	    }
	    else if (count == 1)
	    {
		return NULL;                                                    //returning NULL
	    }

	}

    }
    else if( str == NULL)                                                       //if NULL is passed in string while function call
    {
	str = next_element;                                                     //assigning the value of previously stored positon to string
	my_strtok(str, delim);                                                  //calling the function again with updated string value
    }
}
