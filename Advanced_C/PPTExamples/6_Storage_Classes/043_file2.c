#include<stdio.h>
extern int num;
static int func_2()
{
    printf("num is %d from file2\n", num);
    return 0;
}
int func_1()
{
    func_2();
}
