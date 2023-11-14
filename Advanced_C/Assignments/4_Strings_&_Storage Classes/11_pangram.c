/*


Name: Harsharaj Nath
Date of Submission: 11-07-22
Description: WAP to check given string is Pangram or not


Sample Execution:

Test Case 1:

Enter the string: The quick brown fox jumps over the lazy dog

The Entered String is a Pangram String

Test Case 2:

Enter the string: The quick brown fox jumps over the dog

The Entered String is not a Pangram String


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>

int pangram(char *);                                                            //function prototype

int main()
{
    char str[100];
    int ret;

    printf("Enter the string: ");
    scanf("%[^\n]", str);                                                       //taking the string from user

    ret = pangram(str);                                                         //function call

    if (ret == 0)
	printf("The Entered String is a Pangram String\n");

    else if (ret == 1)
	printf("The Entered String is not a Pangram String\n");

    return 0;
}

int pangram(char *str)                                                          //function definition
{
    int i = 0;
    int flag;
    char alphabet[26] = {0};                                                    //initializing alphabet array with all zeros

    while(str[i] != '\0')                                                       //checking each element of the string 
    {
	if ( str[i] == 'a' || str[i] == 'A')                                    //depending upon the element of string, alphabet array elements are assigned with 1.
	    alphabet[0] = 1;

	if ( str[i] == 'b' || str[i] == 'B')
	    alphabet[1] = 1;

	if ( str[i] == 'c' || str[i] == 'C')
	    alphabet[2] = 1;

	if ( str[i] == 'd' || str[i] == 'D')
	    alphabet[3] = 1;

	if ( str[i] == 'e' || str[i] == 'E')
	    alphabet[4] = 1;

	if ( str[i] == 'f' || str[i] == 'F')
	    alphabet[5] = 1;

	if ( str[i] == 'g' || str[i] == 'G')
	    alphabet[6] = 1;

	if ( str[i] == 'h' || str[i] == 'H')
	    alphabet[7] = 1;

	if ( str[i] == 'i' || str[i] == 'I')
	    alphabet[8] = 1;

	if ( str[i] == 'j' || str[i] == 'J')
	    alphabet[9] = 1;

	if ( str[i] == 'k' || str[i] == 'K')
	    alphabet[10] = 1;

	if ( str[i] == 'l' || str[i] == 'L')
	    alphabet[11] = 1;

	if ( str[i] == 'm' || str[i] == 'M')
	    alphabet[12] = 1;

	if ( str[i] == 'n' || str[i] == 'N')
	    alphabet[13] = 1;

	if ( str[i] == 'o' || str[i] == 'O')
	    alphabet[14] = 1;

	if ( str[i] == 'p' || str[i] == 'P')
	    alphabet[15] = 1;

	if ( str[i] == 'q' || str[i] == 'Q')
	    alphabet[16] = 1;

	if ( str[i] == 'r' || str[i] == 'R')
	    alphabet[17] = 1;

	if ( str[i] == 's' || str[i] == 'S')
	    alphabet[18] = 1;

	if ( str[i] == 't' || str[i] == 'T')
	    alphabet[19] = 1;

	if ( str[i] == 'u' || str[i] == 'U')
	    alphabet[20] = 1;

	if ( str[i] == 'v' || str[i] == 'V')
	    alphabet[21] = 1;

	if ( str[i] == 'w' || str[i] == 'W')
	    alphabet[22] = 1;

	if ( str[i] == 'x' || str[i] == 'X')
	    alphabet[23] = 1;

	if ( str[i] == 'y' || str[i] == 'Y')
	    alphabet[24] = 1;

	if ( str[i] == 'z' || str[i] == 'Z')
	    alphabet[25] = 1;

	i++;
    }

    for (int j = 0; j < 26; j++)                                                //loop to verify the alphabet array
    {
	if (alphabet[j] != 1)                                                   //if atleast one element is not 1, implies that enterted string it is not a pangram string 
	{
	    flag = 1;
	    break;
	}
	else                                                                    //if all emements are 1, implies that enterted string it is a pangram string
	    flag = 0;
    }

    if (flag == 1)                                                              //depeding upon the flag value we return from the function
	return 1;

    else if (flag == 0)
	return 0;
}
