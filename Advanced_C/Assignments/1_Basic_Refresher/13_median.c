/*


Name: Harsharaj Nath
Date of Submission: 08-06-22
Description: WAP to find the median of two unsorted arrays


Sample execution: -

Test Case 1: 

Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5
Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5                         

Test Case 2:

Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 4
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 13 7 5
Median of array1 : 4
Median of array2 : 9.5                                      
Median of both arrays : 6.75


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
int main ()
{
    int i, j, temp, m, n, mid_A_1, mid_A_2, mid_B_1, mid_B_2;				//initialization
    float median_A, median_B, final_median;


    printf("Enter the 'n' value for Array A: ");					//taking size of array A from the user
    scanf("%d", &m);
    int array_A[m];									//initializing array A
    printf("Enter the 'n' value for Array B: ");					//taking size of array B from the user
    scanf("%d", &n);
    int array_B[n];									//initializing array B


    printf("Enter the elements one by one for Array A: \n");				//taking array A elements from the user
    for( i = 1; i <= m; i++ )
    {
	scanf("%d", &array_A[i]);
    }
    printf("Enter the elements one by one for Array B: \n");				//taking array B elements from the user
    for( i = 1; i <= n; i++ )
    {
	scanf("%d", &array_B[i]);
    }


    for ( i = 1; i <= m - 1; i++ )							//bubble sorting array A
    {
	for ( j = 1; j <= m - i; j++ )
	{
	    if ( array_A[j] > array_A[j + 1] )
	    {
		temp = array_A[j];
		array_A[j] = array_A[j + 1];
		array_A[j + 1] = temp;
	    }
	}
    }


    for ( i = 1; i <= n - 1; i++ )							//bubble sorting array B
    {
	for ( j = 1; j <= n - i; j++ )
	{
	    if ( array_B[j] > array_B[j + 1] )
	    {
		temp = array_B[j];
		array_B[j] = array_B[j + 1];
		array_B[j + 1] = temp;
	    }
	}
    }


    if ( (m % 2) == 0 )									//if length of array A is even
    {
	mid_A_1 = array_A[(m / 2)];							//finding the middle element
	mid_A_2 = array_A[(m / 2) + 1];
	median_A = (float)(mid_A_1 + mid_A_2) / 2;					//calculating the median
	printf("Median of array1 : %g\n", median_A);
    }
    else										//if length of array A is odd
    {
	median_A = array_A[( m / 2 ) + 1];						//calculating the median
	printf("Median of array1 : %g\n", median_A);
    }


    if ( ( n % 2) == 0 )								//if length of array B is even
    {
	mid_B_1 = array_B[(n / 2)];							//finding the middle element
	mid_B_2 = array_B[(n / 2) + 1];
	median_B = (float)(mid_B_1 + mid_B_2) / 2;					//calculating the median	
	printf("Median of array2 : %g\n", median_B);
    }
    else										//if length of array B is odd
    {
	median_B = array_B[( n / 2 ) + 1];						//calculating the median	
	printf("Median of array2 : %g\n", median_B);
    }


    final_median = (median_A + median_B) / 2;						//calculating median of both the arrays
    printf("Median of both arrays : %g\n", final_median);

    return 0;
}
