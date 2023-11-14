/*


Name: Harsharaj Nath
Date of Submission: 22-07-22
Description: WAP to convert Little Endian data to Big Endian


Sample execution: -

Test Case 1:

Enter the size: 2
Enter any number in Hexadecimal: ABCD
After conversion CDAB

Test Case 2:

Enter the size: 4
Enter any number in Hexadecimal: 12345678
After conversion 78563412


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
void swap(void *, int);                                                         //prototype for swap() function
int main()
{
    int size;
    void *ptr;

    printf("Enter the size: ");
    scanf("%d", &size);                                                         //taking size from user (either 2 or 4)

    if( size == 2 )                                                             //condition to check if size is 2
    {
	short int num;
	printf("Enter any number in Hexadecimal: ");
	scanf("%hx", &num);                                                     //taking the input

	ptr = &num;                                                             //storing the addrress of num in pointer ptr
	swap(ptr, 2);                                                           //calling the swap function
    }
    else if ( size == 4 )                                                       //condition to check if size is 4
    {
	int num;
	printf("Enter any number in Hexadecimal: ");
	scanf("%x", &num);                                                      //taking the input

	ptr = &num;                                                             //storing the addrress of num in pointer ptr
	swap(ptr, 4);                                                           //calling the swap function
    }
    else                                                                        //if entered size is not 2 or 4
    {
	printf("Error: Please enter 2 for short int and 4 for int data type.\n");
    }
}

void swap (void *ptr, int size)                                                 //function definition
{
    char temp;
    if ( size == 2 )                                                            //check if size is 2
    {                                                                           //swapping the 2 bytes
	temp = *(char *)ptr;
	*(char *)ptr = *(char *)(ptr + 1);
	*(char *)(ptr + 1) = temp;
    }
    else if ( size == 4 )                                                       //check if size is 4
    {                                                                           //swapping 0th byte with 3rd byte
	temp = *(char *)ptr;
	*(char *)ptr = *(char *)(ptr + 3);
	*(char *)(ptr + 3)= temp;

	temp = *(char *)(ptr + 1);                                              //swapping 1st byte with 2nd byte
	*(char *)(ptr + 1) = *(char *)(ptr + 2);
	*(char *)(ptr + 2)= temp;
    }

    printf("After conversion ");
    printf("%x\n", *(int *)ptr);                                                //printing the num
}
