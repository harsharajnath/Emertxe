/*


Name: Harsharaj Nath
Date of Submission: 10-06-22
Description: WAP to toggle 'n' bits from given position of a number


Sample Execution: 

Test Case 1:

Enter the number: 10

Enter number of bits: 3

Enter the pos: 5

Result = 50

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the pos: 2

Result =  9


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int toggle_nbits_from_pos(int, int, int);                                       //function prototype

int main()
{
    int num, n, pos, res = 0;                                                   //initialization

    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);                                            //taking value of num, n and pos from the user

    res = toggle_nbits_from_pos(num, n, pos);                                   //function call

    printf("Result = %d\n", res);                                               //printing the result
}

int toggle_nbits_from_pos(int num, int n, int pos)                              //function definition
{
    int mask, result;                                                           //initialization
    mask = ((1 << n) - 1) << (pos - n + 1);                                     //creating the mask
    result = mask ^ num;                                                        //logic
  //result = (((1 << n) - 1) << (pos - n + 1)) ^ num;				//combined into a single line
    return result;                                                              //returning the result
}
