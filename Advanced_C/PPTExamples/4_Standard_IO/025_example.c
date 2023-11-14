#include <stdio.h>
int main()
{
    char ch = 'y';
    printf("Enter a string: ");
    while (ch != 'n')
    {
	scanf("%c", &ch);
	printf("%c", ch);
    }
    return 0;
}
