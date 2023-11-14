#include <stdio.h>
#include <unistd.h>
int main()
{
    char str[BUFSIZ] = "1";
    while (1)
    {
	printf("%s", str);
	sleep(1);
    }
    return 0;
}
