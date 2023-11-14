/*


Name: Harsharaj Nath
Date of Submission: 10-06-22
Description: WAP to get 'n' bits from given position of a number


Sample Execution: 

Test Case 1:

Enter the number: 12

Enter number of bits: 3

Enter the pos: 4

Result = 3

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the pos: 2

Result =  3


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int get_nbits_from_pos(int, int, int);                                          		//function prototype

int main()
{
    int num, n, pos, res = 0;                                                   		//initialization

    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);                                            		//taking value of num, n and pos from the user

    res = get_nbits_from_pos(num, n, pos);                                      		//function call

    printf("Result = %d\n", res);                                               		//printing the result
}

int get_nbits_from_pos(int num, int n, int pos)                                 		//function definition
{
    int mask, result;                                                           		//initialization
    mask = ((1 << n) - 1) << (pos - n + 1);                                     		//creating the mask
    result = (mask & num) >> (pos - n + 1);                                     		//logic
  //result = ((((1 << n) - 1) << (pos - n + 1)) & num ) >> (pos - n + 1);			//combined into a single line
    return result;                                                              		//returning the result
}
