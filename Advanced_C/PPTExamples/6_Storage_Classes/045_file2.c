#include<stdio.h>
static extern int num;
int func_2()
{
    printf("num is %d from file2\n", num);
    return 0;
}
int func_1()
{
    func_2();
}
