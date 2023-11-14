#include<stdio.h>

/* Program to check if entered character is vowel or not */

int main()
{
char character;
printf("\n**Program to check if entered character is vowel or not**\n\n");
printf("Enter a character: \n");
scanf("%c", &character);

switch (character)
{
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
	printf("You entered a vowel\n");
	break;
    default:
	printf("You entered a consonant\n");
	break;
}

return 0;
}


