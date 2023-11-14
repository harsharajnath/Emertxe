#include <stdio.h>
#include <unistd.h>
int main()
{
    while (1)
    {
	fprintf(stdout, "Hello");
	fprintf(stderr, "World");
    }
    sleep(1);
    return 0;
}
