#include<stdio.h>
#include<stdlib.h>

static int *ptr;

void my_exit(void)
{
    printf("Exiting program\n");
    if (ptr)
    {
	free(ptr);
    }
}
void test(void)
{
    puts("In test");
    exit(0);
}  


int main()
{
    atexit(my_exit);
    ptr = malloc(100);
    test();
    printf("Hello\n");
    return 0;
}
