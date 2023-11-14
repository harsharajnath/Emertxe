/*


Name: Harsharaj Nath
Date of Submission: 14-06-22
Description: WAP to print 'n' bits from LSB of a number


Sample Execution:

Test Case 1:

Enter the number: 10

Enter number of bits: 12

Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 

Test Case 2:

Enter the number: 15

Enter number of bits: 4

Binary form of 15: 1 1 1 1


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int print_bits(int, int);                                                       //function prototype

int main()
{
    int num, n;                                                                 //initializtion
    
    printf("Enter num, n :\n");
    
    scanf("%d%d", &num, &n);                                                    //taking value of num and n from user
    
    printf("Binary form of %d: ", num);
    
    print_bits(num, n);                                                         //function call
    
    printf("\n");

    return 0;
 }
 
 int print_bits(int num, int n)                                                 //function definition
 {
     if ( n > 32 )                                                              //condition check if n is greater than size of integer
     {
         n = 32;                                                                //assigning n as 32
         int i;
         for( i = 0; i < n; i++ )                                               //loop to print n bits from LSB
         {
            if ( num & (1 << (31 - i)) )
	            printf("1 ");
            else
	            printf("0 ");
        }
     }
     else
     {
         int i;
         for( i = 0; i < n; i++ )                                               //loop to print n bits from LSB
         {
            if ( (num >> (n - 1) - i) & 1 )
	            printf("1 ");
            else
	            printf("0 ");
        }
     }
 }
