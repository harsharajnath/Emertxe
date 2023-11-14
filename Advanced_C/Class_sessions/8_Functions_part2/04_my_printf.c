#include<stdio.h>
#include<stdarg.h>
void my_printf(char *format, ... );
int main()
{
    my_printf("Hello %d %d\n", 10, 20);
    return 0;
}

void my_printf(char *format, ... )
{
    int num;
    va_list ap;
    va_start(ap, format);

    while(*format)
    {
	if(*format == '%')
	{
	    format++;
	    if(*format == 'd')
	    {
		num = va_arg(ap, int);
		fprintf(stdout, "%d", num);
		format++;
	    }
	}
	else
	{
	    putchar(*format);
	    format++;
	}
    }
    va_end(ap);
}
