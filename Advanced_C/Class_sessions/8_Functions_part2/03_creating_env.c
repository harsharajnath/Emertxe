#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv, char **envp)
{
    setenv("array","1 2 3 4 5", 0);
    char *ptr;
    ptr = getenv("array");
    printf("%s\n",ptr);
    unsetenv("array");
    return 0;
}
