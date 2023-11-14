#include <stdio.h>
void modify(int num1)
{
    num1 = num1 + 1;
}
int main()
{
    int num1 = 10;
    printf("Before Modification\n");
    printf("num1 is %d\n", num1);
    modify(num1);
    printf("After Modification\n");
    printf("num1 is %d\n", num1);
    return 0;
}
