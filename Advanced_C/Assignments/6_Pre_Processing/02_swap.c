/*


Name: Harsharaj Nath
Date of Submission: 11-08-22
Description: WAP to define a macro swap (t, x, y) that swaps 2 arguments of type t


Sample execution: -

Test Case 1:

1. int
2. char
3. short
4. float
5. double
6. string
Enter you choice : 1

Enter the num1 : 10
Enter the num2 : 20
After Swapping :
num1 : 20
num2 : 10


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>
#include <stdlib.h>
                                                                                //macro definition
#define SWAP(t, a, b)       \
{                           \
    t temp = a;             \
    a = b;                  \
    b = temp;               \
}


int main()
{
    int choice1, num1, num2;                                                    //variable declaration
    char ch1, ch2;
    char choice2 = 'y';
    char str1[20], str2[20], *aptr1, *aptr2;
    short int sh1, sh2;
    float fl1, fl2;
    double db1, db2;
    
    do
    {
        printf("1. int\n2. char\n3. short\n4. float\n5. double\n6. string\n7. Exit\nEnter you choice : ");
	    scanf("%d", &choice1);                                                                                              //reading the choice from user

	    printf("\n");

	    switch(choice1)                                                         //switches cases for choice
	    {
	        case 1:                                                             //case for int
		            printf("Enter the num1 : ");
		            scanf("%d", &num1);
		            printf("Enter the num2 : ");
		            scanf("%d", &num2);

		            SWAP(int, num1, num2);

		            printf("After Swapping :\n");
		            printf("num1 : %d\nnum2 : %d\n", num1, num2);

		            break;

	        case 2:                                                             //case for char
		            printf("Enter the char1 : ");
		            scanf(" %c", &ch1);
		            printf("Enter the char2 : ");
		            scanf(" %c", &ch2);

		            SWAP(char, ch1, ch2);

		            printf("After Swapping :\n");
		            printf("char1 : %c\nchar2 : %c\n", ch1, ch2);

		            break;

	        case 3:                                                             //case for short
		            printf("Enter the short num1 : ");
		            scanf(" %hd", &sh1);
		            printf("Enter the short num2 : ");
		            scanf(" %hd", &sh2);

		            SWAP(short int, sh1, sh2);

		            printf("After Swapping :\n");
		            printf("short num1 : %hd\nshort num2 : %hd\n", sh1, sh2);

		            break;

	        case 4:                                                             //case for float
		            printf("Enter the float num1 : ");
		            scanf(" %f", &fl1);
		            printf("Enter the float num2 : ");
		            scanf(" %f", &fl2);

	    	        SWAP(float, fl1, fl2);

		            printf("After Swapping :\n");
		            printf("float num1 : %f\nfloat num2 : %f\n", fl1, fl2);

		            break;

	       case 5:                                                              //case for double
		            printf("Enter the double num1 : ");
		            scanf(" %lf", &db1);
		            printf("Enter the double num2 : ");
    		        scanf(" %lf", &db2);

	    	        SWAP(double, db1, db2);

		            printf("After Swapping :\n");
		            printf("double num1 : %lf\ndouble num2 : %lf\n", db1, db2);
    
		            break;

	        case 6:                                                             //case for string
		            printf("Enter the string1 : ");
		            scanf(" %s", str1);
		            aptr1 = str1;
		            printf("Enter the string2 : ");
		            scanf(" %s", str2);
		            aptr2 = str2;

		            SWAP(char *, aptr1, aptr2);

		            printf("After Swapping :\n");
		            printf("string1 : %s\nstring2 : %s\n", aptr1, aptr2);

		            break;

	        case 7:                                                             //case for exit
		            exit(0);

	        default:                                                            //default case
		            printf("Error: Please choose correct option\n");
	    }	

	    printf("Do you want to continue? (Y/N) : ");
	    scanf(" %c", &choice2);                                                 //reading choice from user to continue or not

	    printf("-------------------------------------------\n\n");

    }while(choice2 == 'y' || choice2 == 'Y');

    return 0;
}
