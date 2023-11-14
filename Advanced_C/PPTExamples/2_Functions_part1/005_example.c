#include <stdio.h>
void modify(int *iptr)
{
    *iptr = *iptr + 1;
}
int main()
{
    int num = 10;
    printf("Before Modification\n");
    printf("num1 is %d\n", num);
    modify(&num);
    printf("After Modification\n");
    printf("num1 is %d\n", num);
    return 0;
}
