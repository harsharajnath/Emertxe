#include <stdio.h>
#include <unistd.h>
int func_1();
int num;
int main()
{
    while (1)
    {
	num++;
	func_1();
	sleep(1);
    }
    return 0;
}
