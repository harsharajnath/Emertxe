#include<stdio.h>
#include<unistd.h>

int main()
{
    int num;
    while(1)
    {
	printf("HelloWorld");
	scanf("%d", &num);
	printf("Number is entered ");
	sleep(1);
    }
    return 0;
}
