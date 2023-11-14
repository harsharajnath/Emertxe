/*


Name: Harsharaj Nath
Date of Submission: 09-07-22
Description: WAP to implement atoi function


Sample execution: -

Test Case 1 :

Enter a numeric string: 12345
String to integer is 12345

Test Case 2 :

Enter a numeric string: -12345
String to integer is -12345

Test Case 3 :

Enter a numeric string: +12345
String to integer is 12345

Test Case 4 :

Enter a numeric string: +-12345
String to integer is 0

Test Case 5 :

Enter a numeric string: 12345-
String to integer is 12345

Test Case 6 :

Enter a numeric string: abcd12345
String to integer is 0

Test Case 7 :

Enter a numeric string: 12345abcd
String to integer is 12345


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int my_atoi(const char *);                                                      //function prototype

int main()
{
    char str[20];                                                               //array declaration

    printf("Enter a numeric string : ");
    scanf("%s", str);                                                           //taking input from user

    printf("String to integer is %d\n", my_atoi(str));                          //function call
}

int my_atoi( const char str[20])                                                //function definition
{
    int int_val;
    int num = 0;                                                                //initializations
    int index = 0;
    int condition = 0; 

    /* all conditions are available at the end of this program, please refer that for more details */

    if(str[0] >= 48 && str[0] <= 57)                                            //checking for condition 1,6,8
    {
	for ( int i = 0; str[i] != '\0'; i++)
	{

	    if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	    {
		condition = 6;
		break;
	    }
	    else if (str[i] >= 48 && str[i] <= 57)
	    {
		condition = 1;
	    }
	    else if (str[i] == '-' || str[i] == '+')
	    {
		condition = 8;
		break;
	    }
	    else
	    {
		condition = 0;
		break;
	    }

	    index++;

	}
    }


    if(str[0] == '+' )                                                          //checking for condition 2 & 3
    {
	condition = 2;

	if(str[1] == '+' || str[1] == '-')
	{
	    condition = 3;
	}
    }


    if(str[0] == '-')                                                           //checking for condition 4 & 5
    {
	condition = 4;

	if(str[1] == '+' || str[1] == '-')
	{
	    condition = 5;
	}
    }


    if((str[0] >= 65 && str[0] <= 90) || (str[0] >= 97 && str[0] <= 122))       //checking for condition 7
    {
	condition = 7;
    }


    switch (condition)                                                          //switch cases
    {
	case 1:

	    for(int i = 0; str[i] != '\0'; i++)
	    {
		int_val = str[i] - 48;
		num = num * 10 + int_val; 
	    }
	    return num;
	    break;

	case 2:

	    for(int i = 1; str[i] != '\0'; i++)
	    {
		int_val = str[i] - 48;
		num = num * 10 + int_val;
	    }
	    return num;
	    break;

	case 3:

	    return 0;
	    break;

	case 4:

	    for(int i = 1; str[i] != '\0'; i++)
	    {
		int_val = str[i] - 48;
		num = num * 10 + int_val; 
	    }
	    int neg_num = 0 - num;
	    return neg_num;
	    break;

	case 5:

	    return 0;
	    break;

	case 6:

	    for(int i = 0; i< index; i++)
	    {
		int_val = str[i] - 48;
		num = num * 10 + int_val; 
	    }
	    return num;
	    break;

	case 7:

	    return 0;
	    break;

	case 8:

	    for(int i = 0; i< index; i++)
	    {
		int_val = str[i] - 48;
		num = num * 10 + int_val; 
	    }
	    return num;
	    break;

	default:

	    return 0;
    }

}


/*

   CONDITIONS DETAILS

   Condition 1: 12345 -> 12345

   Condition 2: +12345 -> 12345

   Condition 3: ++12345 or +-12345 -> 0

   Condition 4: -12345 -> -12345

   Condition 5: -+12345 or --12345 -> 0

   Condition 6: 12345abcd -> 12345

   Condition 7: abcd12345 -> 0

   Condition 8: 12345- or 12345+ -> 12345

 */
