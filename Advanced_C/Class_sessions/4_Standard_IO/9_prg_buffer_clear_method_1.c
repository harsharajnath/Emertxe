#include<stdio.h>
#include<stdio_ext.h>
#include<ctype.h>

int main()
{
    char ch;
    while((ch = getchar()) != EOF )
    {
	__fpurge(stdin);
	putchar(toupper(ch));
    }

    return 0;
}
	
