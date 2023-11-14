/*


Name: Harsharaj Nath
Date of Submission: 15-07-22
Description: WAP to print all possible combinations of given string.


Sample execution: -

Test Case 1:

Enter a string: abc

All possible combinations of given string :
abc
acb
bca
bac
cab
cba

Test Case 2:

Enter a string: abb

Error: please enter distinct characters.


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h> 

void combination(char *,int ,int );                                             //function prototype for combination()
int my_strlen(char *);                                                          //function prototype for my_strlen()
void swap(char *, char *);                                                      //function prototype for swap()

int main()
{
    char str[100];
    int flag = 0;
    int n;

    printf("Enter a string: ");
    scanf("%100[^\n]",str);                                                 //reading the string from user

    n = my_strlen(str);                                                     //function call - calculating the length of string

    for ( int i = 1; i <= n; i++)                                           //loop to check if duplicate elements present
    {
	for( int j = 0; j < i  ; j++)
	{
	    if(str[j] == str[i])
	    {
		flag = 1;                                                   //if atleast one duplicate element found, set flag = 1 and break
		break;
	    }
	}
    }

    if (flag == 1)
    {    
	printf("\nError: please enter distinct characters.\n");             //printing error message when duplicate element is present
    }
    else if (flag == 0)
    {   
	printf("\nAll possible combinations of given string:\n");
	combination(str,0,n-1);                                             //else calling the combination() funtion
    }

    return 0;
}

int my_strlen(char *str)                                                        //function definition for my_strlen()
{
    int i;
    int count = 0;                                                              //initializing count with 0
    for( i = 0; str[i] != '\0'; i++)
    {
	count++;                                                                //incrementing count till '\0' character is found
    }
    return count;                                                               //returning the count
}

void swap(char *x, char *y)	      	                                        //function definition for swap()
{
    char temp;                                                                  //logic
    temp = *x;
    *x = *y;
    *y = temp;
}

void combination(char *str, int curr_index, int last_index)                     //function definition for combination()             
{
    int pos;

    if (curr_index == last_index)                                               //condition to print the string
    {    
	printf("%s\n", str);
    }
    else
    {
	for (int pos = curr_index; pos <= last_index; pos++)
	{
	    swap((str + curr_index), (str + pos));                              //swapping and fixing one index value at a time

	    combination(str, curr_index + 1, last_index);                       //recursive function call with incremented index position

	    swap((str + curr_index), (str + pos));                              //backtracking
	}
    }
}

