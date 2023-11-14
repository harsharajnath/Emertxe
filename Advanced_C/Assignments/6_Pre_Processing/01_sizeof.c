/*


Name: Harsharaj Nath
Date of Submission: 10-08-22
Description: WAP to define a macro SIZEOF(x), without using sizeof operator


Sample execution: -

Test Case 1:

Size of int : 4 bytes
Size of char : 1 byte
Size of float : 4 bytes
Size of double : 8 bytes
Size of unsigned int : 4 bytes
Size of long int : 8 bytes


#########################################_Program_begins_from_here_######################################### */


#include <stdio.h>

#define SIZEOF(x)   (char *)(&x + 1) - (char *)(&x)                             //macro definition

int main()
{
    int sint;                                                                   //variable declarations
    unsigned int uint;

    char schar;
    unsigned char uchar;

    float fl;
    double db;

    long int lint;
    unsigned long int ulint;

    long double ld;
    long long int llint;

    short int shint;
    unsigned short int ushint;

    printf("Size of int : %ld bytes\n", SIZEOF(sint));                          //printing the size of data types using the macro SIZEOF(x)

    printf("Size of char : %ld bytes\n", SIZEOF(schar));

    printf("Size of float : %ld bytes\n", SIZEOF(fl));

    printf("Size of double : %ld bytes\n", SIZEOF(db));

    printf("Size of unsigned int : %ld bytes\n", SIZEOF(uint));

    printf("Size of long int : %ld bytes\n", SIZEOF(lint));

    printf("Size of unsigned long int : %ld bytes\n", SIZEOF(ulint));

    printf("Size of long double : %ld bytes\n", SIZEOF(ld));

    printf("Size of unsigned char : %ld bytes\n", SIZEOF(uchar));

    printf("Size of long long int : %ld bytes\n", SIZEOF(llint));

    printf("Size of short int : %ld bytes\n", SIZEOF(shint));

    printf("Size of unsigned short int : %ld bytes\n", SIZEOF(ushint));

    return 0;
}
