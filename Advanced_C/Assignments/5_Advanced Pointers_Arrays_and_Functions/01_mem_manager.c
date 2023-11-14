/*


Name: Harsharaj Nath
Date of Submission: 12-08-22
Description: Provide a menu to manipulate or display the value of variable of type t

Sample execution: -

Test Case 1:

Menu :
1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1

Enter the type you have to insert:
1. int
2. char
3. float
4. double

Choice ---> 2

Enter the char : k

1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 3
-------------------------
0 -> k
-------------------------

1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 1

Enter the type you have to insert:
1. int
2. char
3. float
4. double

Choice ---> 1

Enter the int : 10

1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 3
------------------------
0 -> k (char)
1 -> 10 (int)
------------------------

1. Add element
2. Remove element
3. Display element
4. Exit from the program

Choice ---> 2
0 -> k
1 -> 10

Enter the index value to be deleted : 0

index 0 successfully deleted.

1. Add element
2. Remove element
3. Display element
4. Exit from the program
Choice ---> 4


#########################################_Program_begins_from_here_######################################### */


#include<stdio.h>
#include<stdlib.h>

/*-------flags initialization--------*/
int ch1_flag = 0;
int ch2_flag = 0;
int int_flag = 0;
int short_flag = 0;
int float_flag = 0;
int double_flag = 0;

int only_double = 0;
int int_or_float = 0;
/*-----------------------------------*/

int add_element(void *);                                                        //function prototype for add_element()
int remove_element(void *);                                                     //function prototype for remove_element()
void display_element(void *);                                                   //function prototype for display_element()

int main()
{
    void *ptr = malloc(8);                                                      //dynamically allocating memory
    int choice1;

    while(1)
    {
	printf("Menu :\n1. Add element\n2. Remove element\n3. Display element\n4. Exit from the program\n\n");
	printf("Choice ---> ");
	scanf("%d", &choice1);                                                                                                  //reading choice from user

	if(choice1 == 1)                                                                                                        //for adding elements
	{
	    add_element(ptr);                                                   //function call
	}
	else if(choice1 == 2)                                                                                                   //removing elements
	{
	    if(ch1_flag == 0 && ch2_flag == 0 && short_flag == 0 && int_flag == 0 && float_flag == 0 && double_flag == 0)       //checking if no elements present
	    {
		printf("\nNo Elements found\n\n");
	    }
	    else                                                                //if elements present
	    {
		display_element(ptr);                                           //function call
		remove_element(ptr);                                            //function call
	    }
	}
	else if(choice1 == 3)                                                                                                   //displaying elements
	{
	    if(ch1_flag == 0 && ch2_flag == 0 && short_flag == 0 && int_flag == 0 && float_flag == 0 && double_flag == 0)       //checking if no elements present
	    {
		printf("\nNo Elements found\n\n");
	    }
	    else
	    {
		display_element(ptr);                                           //function call
	    }
	}
	else if(choice1 == 4)                                                   //for exit
	{
	    free(ptr);                                                          //freeing dynamically allocated memory
	    ptr = NULL;
	    exit(0);
	}
	else
	{
	    printf("\nError: Please enter a correct choice\n\n");               //error message
	}

	printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    }

    return 0;
}


int add_element(void *ptr)                                                      //function definition of add_element() - Function used for adding an element
{
    int choice2;
    printf("\nEnter the type you have to insert:\n1. char\n2. short\n3. int\n4. float\n5. double\n\n");
    printf("Choice ---> ");
    scanf("%d", &choice2);                                                      //taking choice of data type from user

    if(choice2 == 1)                                                            //for character data type [2 Bytes, i.e Total 2 Characters]
    {
	if(ch1_flag == 0)
	{
	    printf("\nEnter the char: ");
	    scanf(" %c", ((char *)ptr));                                        //reading the character from user [for 1st Byte]
	    printf("\n");
	    ch1_flag = 1;                                                       //set the ch1_flag to 1
	}
	else if(ch2_flag == 0)
	{
	    printf("\nEnter the char: ");
	    scanf(" %c", ((char *)ptr + 1));                                    //reading the character from user [for 2nd Byte]
	    printf("\n");
	    ch2_flag = 1;                                                       //set the ch2_flag to 1
	}
	else
	    printf("\nError: Memory is Full\n\n");                              //if both ch1_flag and ch2_flag are 1 then print error message
    }
    else if(choice2 == 2)                                                       //for short data type [2 Bytes]
    {
	if(short_flag == 0)
	{
	    printf("\nEnter the short: ");
	    scanf("%hd", ((short *)ptr + 1));                                   //reading the short from user 
	    printf("\n");
	    short_flag = 1;                                                     //set the short_flag to 1
	}
	else
	    printf("\nError: Memory is Full\n\n");                              //if short_flag is 1 then print error message
    }
    else if(choice2 == 3)                                                       //for int data type [4 Bytes]
    {
	if(int_flag == 0 && float_flag == 0)                                    //if both flags are 0 then only we can store
	{
	    printf("\nEnter the int: ");
	    scanf("%d", ((int *)ptr + 1));                                      //reading the integer from user
	    printf("\n");
	    int_flag = 1;                                                       //set the int_flag to 1
	    float_flag = 1;                                                     //set the float_flag to 1
	    int_or_float = 0;                                                   //int_or_float = 0 for int
	}
	else
	    printf("\nError: Memory is Full\n\n");                              //if both int_flag and float_flag are 1 then print error message
    }
    else if(choice2 == 4)                                                       //for float data type [4 Bytes]
    {
	if(int_flag == 0 && float_flag == 0)                                    //if both flags are 0 then only we can store
	{
	    printf("\nEnter the float: ");
	    scanf("%f", ((float *)ptr + 1));                                    //reading the float from user
	    printf("\n");
	    int_flag = 1;                                                       //set the int_flag to 1
	    float_flag = 1;                                                     //set the float_flag to 1
	    int_or_float = 1;                                                   //int_or_float = 1 for float
	}
	else
	    printf("\nError: Memory is Full\n\n");                              //if both int_flag and float_flag are 1 then print error message
    }
    else if(choice2 == 5)                                                       //for double data type [8 Bytes]
    {
	if(ch1_flag == 0 && ch2_flag == 0 && short_flag == 0 &&  int_flag == 0 && float_flag == 0)      //if all flags are 0 then only we can store
	{
	    printf("\nEnter the double: ");
	    scanf("%lf", ((double *)ptr));                                      //reading the double from user
	    printf("\n");

	    ch1_flag = 1;                                                       /*set all flags to 1*/
	    ch2_flag = 1;
	    short_flag = 1;
	    int_flag = 1;
	    float_flag = 1;
	    double_flag = 1;

	    only_double = 1;                                                    //only_double = 1 indicates only double data is stored                                             
	}
	else
	    printf("\nError: Memory is Full\n\n");                              //if all flag are 1 then print error message
    }
    else
    {
	printf("\nError: Please enter a correct choice\n\n");                   //error message
    }

    return 0;
}

int remove_element(void *ptr)                                                   //function definition of remove_element() - Function used for removing an element
{
    int index;

    printf("Enter the index value to be deleted : ");
    scanf("%d", &index);                                                        //reading the index from the user

    if(only_double == 1)                                                        //if only double data is present
    {
	if(index == 0)                                                          //for double index will is 0 only
	{
	    ch1_flag = 0;                                                       /*set all flags to 0*/
	    ch2_flag = 0;
	    short_flag = 0;
	    int_flag = 0;
	    float_flag = 0;
	    double_flag = 0;
	    only_double = 0;
	    printf("\nindex [%d] successfully deleted.\n\n", index);
	}
	else
	    printf("\nError: invalid Index\n\n");                               //error message
    }
    else if(only_double == 0)                                                   //if other data types are present except double
    {
	if( (index == 0 && ch1_flag == 1) || (index == 1 && ch2_flag == 1) || (index == 2 && short_flag == 1) || (index == 4 && (int_flag == 1 || float_flag == 1)) )       //condition checking
	{
	    if (index == 0)
	    {
		ch1_flag = 0;                                                   //set ch1_flag to 0
	    }
	    else if(index == 1)
	    {
		ch2_flag = 0;                                                   //set ch2_flag to 0
	    }

	    else if(index == 2)
	    {
		short_flag = 0;                                                 //set short_flag to 0
	    }

	    else if(index == 4)
	    {
		int_flag = 0;                                                   //set both int_flag and float_flag to 0
		float_flag = 0;
	    }

	    printf("\nindex [%d] successfully deleted.\n\n", index);
	}
	else
	    printf("\nError: invalid Index\n\n");                               //error message
    }

    return 0;
}

void display_element(void *ptr)                                                 //function definition of display_element() - Function used for display an element
{
    if(double_flag == 1)                                                        /*check if double data is present*/
    {
	printf("\n[0] --> %lf (double)\n", *((double *)ptr));
    }
    else if (int_or_float == 0)                                                 /*check if int data is present*/
    {                                                                           /*printing data accordingly*/
	if(ch1_flag == 1)
	{
	    printf("\n[0] --> %c (char)\n", *((char *)ptr));
	}
	if(ch2_flag == 1)
	{
	    printf("\n[1] --> %c (char)\n", *((char *)ptr + 1));
	}
	if(short_flag == 1)
	{
	    printf("\n[2] --> %hd (short)\n", *((short *)ptr + 1));
	}   
	if(int_flag == 1)
	{
	    printf("\n[4] --> %d (int)\n", *((int *)ptr + 1));
	}
    }

    else if (int_or_float == 1)                                                 /*check if float data is present*/
    {                                                                           /*printing data accordingly*/
	if(ch1_flag == 1)
	{
	    printf("\n[0] --> %c (char)\n", *((char *)ptr));
	}
	if(ch2_flag == 1)
	{
	    printf("\n[1] --> %c (char)\n", *((char *)ptr + 1));
	}
	if(short_flag == 1)
	{
	    printf("\n[2] --> %hd (short)\n", *((short *)ptr + 1));
	}
	if(float_flag == 1)
	{
	    printf("\n[4] --> %f (float)\n", *((float *)ptr + 1));
	}
    }
    else                                                                        /*if only character and short data are present*/
    {                                                                           /*printing data accordingly*/
	if(ch1_flag == 1)
	{
	    printf("\n[0] --> %c (char)\n", *((char *)ptr));
	}
	if(ch2_flag == 1)
	{
	    printf("\n[1] --> %c (char)\n", *((char *)ptr + 1));
	}
	if(short_flag == 1)
	{
	    printf("\n[2] --> %hd (short)\n", *((short *)ptr + 1));
	}
    }

    printf("\n");
}
