#include <stdio.h>
#include <ctype.h>
int main()
{
    int ch;
    for ( ; (ch = getc(stdin)) != EOF; )
    {
	putc(toupper(ch), stdout);
    }
    puts("EOF Received");
    return 0;
}
