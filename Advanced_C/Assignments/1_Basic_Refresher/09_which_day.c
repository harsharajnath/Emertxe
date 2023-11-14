/*


Name: Harsharaj Nath
Date of Submission: 22-05-22
Description: WAP to find which day of the year


Sample execution: -

Test Case 1:

Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 2
The day is Tuesday

Test Case 2:

Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3
The day is Wednesday

Test Case 3: 

Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 8
Error: Invalid input, first day should be > 0 and <= 7

Test Case 4:

Enter the value of 'n' : 0
Error: Invalid Input, n value should be > 0 and <= 365

Test Case 5:

Enter the value of 'n' : 366
Error: Invalid Input, n value should be > 0 and <= 365

#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int nth_day, start_day, value, calculation;								//initialization
    printf("Enter the value of 'n' : ");
    scanf("%d", &nth_day);										//taking the input from the user
    if ( nth_day >= 1 && nth_day <= 365 )								//condition to check if entered day is within the range
    {
	printf("Choose First Day :\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\nEnter the option to set the first day : ");
	scanf("%d", &start_day);									//taking the starting day from the user
	if ( start_day > 0 && start_day <= 7 )								//condition to check if entered starting day is within the range
	{
	    calculation = (nth_day + start_day - 1) % 7;			    				//logic for calculation

	    if ( calculation == 0 )									//condtion to elimiate the problem of ambiguity for value 0 and 7
	    {
		value = 7;
	    }
	    else
	    {
		value = calculation;
	    }

	    switch(value)										//switch case for different days
	    {
		case 1:
		    printf("\nThe day is Sunday\n");
		    break;
		case 2:
		    printf("\nThe day is Monday\n");
		    break;
		case 3:
		    printf("\nThe day is Tuesday\n");
		    break;
		case 4:
		    printf("\nThe day is Wednesday\n");
		    break;
		case 5:
		    printf("\nThe day is Thursday\n");
		    break;
		case 6:
		    printf("\nThe day is Friday\n");
		    break;
		case 7:
		    printf("\nThe day is Saturday\n");
		    break;
	    }
	}
	else
	{
	    printf("Error: Invalid input, first day should be > 0 and <= 7\n");					//error message
	}

    }
    else
    {
	printf("Error: Invalid Input, n value should be > 0 and <= 365\n");					//error message
    }

    return 0;
}

