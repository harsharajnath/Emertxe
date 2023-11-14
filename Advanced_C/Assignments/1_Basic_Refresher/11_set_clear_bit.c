/*


Name: Harsharaj Nath
Date of Submission: 02-06-22
Description: WAP to check N th bit is set or not, If yes, clear the M th bit


Sample execution: -

Test Case 1:

Enter the number: 19

Enter 'N': 1

Enter 'M': 4

Updated value of num is 3 

Test Case 2:

Enter the number: 19

Enter 'N': 2

Enter 'M': 4

Updated value of num is 19 


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int num, updated_num, mask, M, N;							//initialization
    printf("Enter the number: ");							//reading input for user
    scanf("%d", &num);
    printf("Enter 'N': ");
    scanf("%d", &N);
    printf("Enter 'M': ");
    scanf("%d", &M);

    if ( ((num >> N) & 1) == 1 )							//condition to check if Nth bit is set
    {
	mask = ~(1<<M);									//mask for clearing a bit
	updated_num = num & mask;							//clearing the Mth bit
	printf("Updated value of num is %d\n", updated_num);
    }
    else
    {
	updated_num = num;
	printf("Updated value of num is %d\n", updated_num);
    }

    return 0;
}
