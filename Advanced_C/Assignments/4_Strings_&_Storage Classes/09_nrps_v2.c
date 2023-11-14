/*


Name: Harsharaj Nath
Date of Submission: 15-07-22
Description: Generate consecutive NRPS of length n using k distinct character


Sample execution: -

Test Case 1:

Enter the number characters C : 3
Enter the Length of the string N : 6
Enter 3 distinct characters : a b c
Possible NRPS is abcbca

Test Case 2:

Enter the number characters C : 3
Enter the Length of the string N : 7
Enter 3 distinct characters : a b a
Error : Enter distinct characters


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
void nrps(char *, int, int);                                                    //function prototype of nrps()
void swap_string(char *, int);                                                  //function prototype of swap_string()

int main()
{

    char str[100];                                                              //initialization
    int flag1 = 0;
    int n, len;

    printf("Enter the number characters C : ");
    scanf("%d", &n);                                                            //taking the number of characters from user

    if( n > 0 )                                                                 //condition to check if no. of characters is greater than 0
    {
	printf("Enter the Length of the string N : ");
	scanf("%d", &len);                                                      //taking the length of string from user

	if( len > 0 )                                                           //condition to check if length of string is greater than 0    
	{
	    printf("Enter %d distinct characters :\n", n);
	    for( int i = 0; i <= n; i++ )                                       //reading the string from user character by character
	    {
		if( i == n )
		{
		    str[i] = '\0';
		}
		else
		{
		    scanf("\n%c", &str[i]);
		}
	    }

	    for ( int i = 1; i <= n; i++)                                       //loop to check if duplicate elements present
	    {
		for( int j = 0; j < i  ; j++)
		{
		    if(str[j] == str[i])
		    {  
			flag1 = 1;                                              //if atleast one duplicate element found, set flag1 = 1 and break
			break;
		    }
		}
	    }

	    if (flag1 == 1)
	    {
		printf("\nError: please enter distinct characters.\n");         //printing error message when duplicate element is present
	    }
	    else if (flag1 == 0)
	    {
		printf("\nPossible NRPS is ");
		nrps(str, n, len);                                              //else calling the nrps() funtion
		printf("\n");
	    }
	}
	else
	    printf("Error: Enter a positive string length");                    //error message when given string length is 0 or negative
    }
    else
	printf("Error: Enter positive number of characters");                   //error message when given no. of characters is 0 or negative

    return 0;

}

void nrps(char *str ,int n, int len)
{
    int i;
    int val = 0;
    int count = 0;

    for (i = 0; i < len; i++)
    {
	if(i%n == 0 && i != 0)
	{
	    val++;
	}
	printf("%c", *(str+((i+val)%n)));
    }
    printf("\n");
}

