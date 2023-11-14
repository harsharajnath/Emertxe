/*


Name: Harsharaj Nath
Date of Submission: 09-07-22
Description: WAP to implement itoa function


Sample execution: -

Test Case 1:

Enter the number : 1234
Integer to string is 1234

Test Case 2:

Enter the number : -1234
Integer to string is -1234

Test Case 3:

Enter the number : +1234
Integer to string is 1234

Test Case 4:

Enter the number : a1234
Integer to string is 0


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int itoa(int num, char *str);                                                   //function prototype

int main()
{
    int num = 0;                                                                //initializing num with 0 (else num will take garbage value for non-integer input like abc123)
    char str[10];                                                               //declaration
    
    printf("Enter the number: ");
    scanf("%d", &num);                                                          //taking input from user
    
    itoa(num, str);                                                             //function call
    
    printf("Integer to string is %s\n", str);                                   //printing interger to ascii
}

int itoa(int num, char *str)                                                    //function definition
{
    int count=0;                                                                //initializations
    int number = num;
    int rev_num = 0;
    int rem1 = 0;
    int rem2 = 0;
    
    if( num != 0 )
    {
        while ( number != 0 )                                                   //counting the digits in the entered number
        {
            count++;
            number = number / 10;
        }
    }
     
    if ( num > 0 )                                                              //if number is positive
    {
        if( count > 1 )                                                         //if number of digits more than 1
        {
            for ( int i = 0; i < count; i++ )                                   //reversing the number 
            {   
                rem1 = num % 10;
                rev_num = rev_num * 10 + rem1;
                num = num / 10;
            }
        }
        
        for ( int i = 0; i <= count; i++ )                                      //logic to convert integer to ascii
        {
            rem2 = rev_num % 10;
            str[i] = rem2 + 48;
            rev_num = rev_num / 10;
            
            if ( i == count)                                                    //adding NULL at the end
            {
                str[i] = '\0';
            }
        }
        
    }
    else if ( num < 0 )                                                         //if number is negative
     {
        if( count > 1 )                                                         //if number of digits more than 1
        {
            for ( int i = 0; i < count; i++)                                    //reversing the number
            {   
                rem1 = num % 10;
                rev_num = rev_num * 10 + rem1;
                num = num / 10;
            }
            
            rev_num = 0 - rev_num;                                              //removing the -ve sign from the integer
        }
        
        for ( int i = 1; i <= (count + 1); i++)                                 //logic to convert integer to ascii
        {
            str[0] = '-';                                                       //adding ascii '-' in the 0th index
            rem2 = rev_num % 10;
            str[i] = rem2 + 48;
            rev_num = rev_num / 10;
            
            if ( i == (count+1))                                                //adding NULL at the end
            {
                str[i] = '\0';
            }
        }
        
    }
    else if ( num == 0 )                                                        //if number is 0
    {
        str[0] = '0';
        str[1] = '\0';
    }
}
