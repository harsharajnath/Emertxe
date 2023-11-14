#include <stdio.h>
int main(int argc, char **argv)
{
    printf("No of argument(s): %d\n", argc);
    printf("List of argument(s):\n");
    for (int i = 0; i < argc; i++)
    {
	printf("\t%d - \"%s\"\n", i + 1, argv[i]);
    }
    return 0;
}
