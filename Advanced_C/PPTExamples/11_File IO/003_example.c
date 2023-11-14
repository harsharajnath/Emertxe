#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    char ch;
    fptr = fopen("/etc/shells", "r");
    /* Need to do error checking on fopen() */
    while (ch = fgetc(fptr))
    {
	if (feof(fptr))
	    break;
	fputc(ch, stdout);
    }
    fclose(fptr);
    return 0;
}
