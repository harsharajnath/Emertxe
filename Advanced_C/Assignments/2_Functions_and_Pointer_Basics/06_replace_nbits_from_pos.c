/*


Name: Harsharaj Nath
Date of Submission: 14-06-22
Description: WAP to put the (b-a+1) lsb’s of num into val[b:a]


Sample execution: -

Test Case 1:

Enter the value of 'num' : 11
Enter the value of 'a' : 3
Enter the value of 'b' : 5
Enter the value of 'val': 174
Result : 158


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);			//function prototype

int main()
{
    int num, a, b, val, res = 0;				//initialization

    printf("Enter num, a, b, and val:");

    scanf("%d%d%d%d", &num, &a, &b, &val);			//taking value of num, a, b and val from user

    if ( b < a || b > 31 )					//condition check for b
    {
	printf("Error: Please enter b within the range (a <= b <= 31)\n");
    }
    else
    {
	res = replace_nbits_from_pos(num, a, b, val);		//function call

	printf("Result = %d\n", res);
    } 

    return 0;
}

int replace_nbits_from_pos(int num, int a, int b, int val)	//function definition
{
    int n, result, nbitsfromnum, updated_val, mask;
    n = b - a + 1;
    int pos = b;

    nbitsfromnum = (((1 << n) - 1) & num) ;

    mask = ~(((1 << n) - 1) << (pos - n + 1));

    updated_val = mask & val;

    result = updated_val | nbitsfromnum << (pos - n + 1);

    //result = ((~(((1 << n) - 1) << (pos - n + 1))) & val) | ( (((1 << n) - 1) & num) << (pos - n + 1));	//combined into a single line

    return result;
}
