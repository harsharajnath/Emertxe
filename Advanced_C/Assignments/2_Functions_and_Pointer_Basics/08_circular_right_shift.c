/*


Name: Harsharaj Nath
Date of Submission: 14-06-22
Description: WAP to implement Circular right shift


Sample execution: -

Test Case 1:

Enter num: 12
Enter n : 3
Result : 10000000 00000000 00000000 00000001

Test Case 2: 

Enter num: -12
Enter n : 3
Result : 10011111 11111111 11111111 11111110


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int circular_right(int, int);                                                   //function prototype

int print_bits(int);                                                            //function prototype

int main()
{
    int num, n, ret;                                                            //initialization

    printf("Enter the num:");
    scanf("%d", &num);                                                          //taking num value from user

    printf("Enter n:");
    scanf("%d", &n);                                                            //taling n value from user

    ret = circular_right(num, n);                                               //function call

    print_bits(ret);                                                            //function call
}

int circular_right(int num, int n)                                              //function defintion
{
    int result, updated_num, n_lsb_bits;                                        //initialization

    updated_num = (num >> n) & (~(((1 << n) - 1 ) << 32 - n ));                 //right shifting num by n bits (n msb bits updated with 0's)

    n_lsb_bits = (((1 << n) - 1) & num) << (32 - n);                            //getting n lsb bits and storing them towards msb

    result = n_lsb_bits | updated_num;                                          //bitwise OR operation to get the final result

    return result;                                                              //returning result
}

int print_bits(int ret)                                                         //function definition
{
    printf("Result in Binary: ");
    for( int i = 0; i < 32; i++ )                                               //for loop to print result in binary form
    {
	if ( ret & (1<<(31 - i)) )
	    printf("1 ");
	else
	    printf("0 ");
    }
    printf("\n");
}
