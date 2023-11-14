/*


Name: Harsharaj Nath
Date of Submission: 10-06-22
Description: WAP to replace 'n' bits of a given number


Sample Execution: 

Test Case 1:

Enter the number: 10

Enter number of bits: 3

Enter the value: 12

Result = 12

Test Case 2:

Enter the number: 15

Enter number of bits: 2

Enter the value: 1

Result =  13


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int replace_nbits(int, int, int);						//function prototype

int main()
{
    int num, n, val, res = 0;							//initialization

    printf("Enter num, n and val:");						//taking value of num, n and val from user
    scanf("%d%d%d", &num, &n, &val);				

    res = replace_nbits(num, n, val);						//function call

    printf("Result = %d\n", res);						//printing the result
}


int replace_nbits(int num, int n, int val)					//function definition
{
    int bits, updated_num, result;						//initialization
    
    bits = ((1 << n) - 1) & val;						//getting n bits from LSB of val
    
    updated_num = (~((1 << n) - 1)) & num;					//clearing n bits from LSB of num
    
    result = updated_num | bits;						//replacing n bits
    
  //result = ((~((1 << n) - 1)) & num) | (((1 << n) - 1) & val);		//combined into a single line
    
    return result;								//returning the result
}
