/*


Name: Harsharaj Nath
Date of Submission: 27-05-22
Description: WAP to generate AP, GP, HP series


Sample execution: -

Test Case 1:

Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': 5
AP = 2, 5, 8, 11, 14
GP = 2, 6, 18, 54, 162
HP = 0.5, 0.2, 0.125, 0.0909091, 0.0714285

Test Case 2:

Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': -5
Invalid input


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int i, ap, gp, first_num, nth_term, comm_diff;				//initialization
    float hp;
    printf("Enter the First Number 'A': ");					//taking input from user
    scanf("%d", &first_num);
    printf("Enter the Common Difference / Ratio 'R': ");			//taking input from user
    scanf("%d", &comm_diff);
    printf("Enter the number of terms 'N': ");					//taking input from user
    scanf("%d", &nth_term);
    if ( nth_term < 1 )								//checking if number of terms to be generated is negative
    {
	printf("Invalid input\n");
    }
    else
    {
	printf("AP = ");
	ap = first_num;
	for ( i = 0; i < nth_term; i++ )					//loop for generating AP series
	{
	    printf(" %d", ap);
	    ap = ap + comm_diff;						//calculating the AP
	    if ( i < nth_term - 1 )
	    {
		printf(",");
	    }
	}


	printf("\nGP = ");
	gp = first_num;
	for ( i = 0; i < nth_term; i++ )					//loop for generating GP series
	{
	    printf(" %d", gp);
	    gp = gp * comm_diff;						//calculating the GP
	    if ( i < nth_term - 1 )
	    {
		printf(",");
	    }
	}


	printf("\nHP = ");
	ap = first_num;
	hp = 1 / (float) ap;
	for ( i = 0; i < nth_term; i++ )					//loop for generating HP series
	{
	    printf(" %f", hp);
	    ap = ap + comm_diff;
	    hp = 1 / (float) ap;						//calculating the HP
	    if ( i < nth_term - 1 )
	    {
		printf(",");
	    }
	}


	printf("\n");
    }

    return 0;
}
