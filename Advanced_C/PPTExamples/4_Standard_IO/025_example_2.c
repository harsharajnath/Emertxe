#include <stdio.h>
#include <stdio_ext.h>
int main()
{
    char ch = 'y';
    printf("Enter a string: ");
    while (ch != 'n')
    {
	scanf("%c", &ch);
	while (getchar() != '\n');
	printf("%c", ch);
    }
    return 0;
}
