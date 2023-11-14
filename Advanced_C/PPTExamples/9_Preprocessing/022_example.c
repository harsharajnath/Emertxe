#include <stdio.h>
#define METHOD	1
int main()
{
    char msg[] = "Hello World";
#if METHOD == 1
    puts(msg);
#elif METHOD == 2
    printf("%s\n", msg);
#else
    int i;
    for (i = 0; i < 12; i++)
    {
	putchar(msg[i]);
    }
#endif
    return 0;
}
