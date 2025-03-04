/*


Name: Harsharaj Nath
Date of Submission: 14-06-22
Description: WAP to implement Circular left shift


Sample execution: -

Test Case 1:

Enter num: 12
Enter n : 3
Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0

Test Case 2:

Enter num: -2
Enter n : 3
Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int circular_left(int, int);                                                    //function prototype

int print_bits(int);                                                            //function prototype

int main()
{
    int num, n, ret;                                                            //initialization
    
    printf("Enter the num:");
    scanf("%d", &num);                                                          //taking num value from user
    
    printf("Enter n:");
    scanf("%d", &n);                                                            //taking n value from user

    ret = circular_left(num, n);                                                //function call
    
    print_bits(ret);                                                            //function call
}

int circular_left(int num, int n)                                               //function defintion
{
    int result, updated_num, n_msb_bits;                                        //initialization
    
    updated_num = num << n;                                                     //left shifting num by n bits (n bits filled with 0's)
    
    n_msb_bits = ((((1<<n) - 1) << (31 - n)) & num) >> (31 - n);                //getting n msb bits and storing them towards lsb
    
    result = n_msb_bits | updated_num;                                            //bitwise OR operation to get the final result
    
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