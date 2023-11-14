#include<stdio.h>
#include<unistd.h>

int main()
{
    while(1)
    {
	putc('A', stderr);
	sleep(1);
    }
    return 0;
}
