#include <stdio.h>
typedef int (*fptr)(int, int);
int add(int num1, int num2)
{
    return num1 + num2;
}
int main()
{
    fptr function;
    function = add;
    printf("%d\n", function(2, 4));
    return 0;
}
