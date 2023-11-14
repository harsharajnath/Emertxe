/*


Name: Harsharaj Nath
Date of Submission: 10-07-22
Description: Squeeze the character in s1 that matches any character in the string s2


Sample execution: -

Test Case 1:

Enter s1 : Dennis Ritchie
Enter s2 : Linux
After squeeze s1 : Des Rtche

Test Case 2:

Enter s1 : Welcome
Enter s2 : Emertxe
After squeeze s1 : Wlco


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

void squeeze(char*, char*);                                                     //function prototype

int main()
{
    char str1[30], str2[30];

    printf("Enter string1: ");
    scanf("%[^\n]", str1);                                                      //reading string 1 from user


    printf("Enter string2: ");
    scanf("\n %[^\n]", str2);                                                   //reading string 2 from user

    squeeze(str1, str2);                                                        //function call

    printf("After squeeze s1 : %s\n", str1);                                    //printing the squeezed string

}

void squeeze(char* str1, char* str2)                                            //function definition
{
    int i = 0;

    while(str1[i] != '\0')                                                      //traversing the whole string 1
    {
	int flag = 0;                                                           //initializaing the flag with 0

	for( int j = 0; str2[j] != '\0'; j++)                                   //loop to compare each element of string 1 with string 2
	{

	    if(str1[i] == str2[j])                                              //if character match found
	    {
		int k = i;
		while(str1[k] != '\0')                                          //loop to left shift all the elements by one position 
		{
		    str1[k] = str1[k+1];
		    k++;

		}
		flag = 1;                                                       //flag is set to 1 when character match found
		break;
	    }
	}

	if (flag == 0)                                                          //if no character matches, i is incremented
	{
	    i++;
	}                                                                       //else i value remains the same for next iteration
    }
}
